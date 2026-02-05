#include<iostream>
#include<thread>
#include<queue>
#include<mutex>//thread safty
//preventing race condiions
#include<condition_variable>
//for thread coordination and producer consumer and job queues
#include<chrono>//for time handling
#include<cmath>
#include<functional>//callbacks objects 
#include<atomic>
//lock free thread safe variables
#include<future>//async and futures
#include<vector>
using namespace std;
class Location{
    public:
    int x, y;
    Location(int x=0, int y=0){
        this->x=x;
        this->y=y;
    }
    double distance(const Location& loc){
        return sqrt(pow(x-loc.x,2)+pow(y-loc.y,2));
    }

};
    class Driver{
        public:
        int id;
        Location loc;
        bool available;
        Driver(int id, Location loc){
            this->id=id;
            this->loc=loc;
            available=true;
        }
    };
    class DriverManager{
        public:
        //producer-consumer+resource pooling
        // lets take shared variables Drivers and Rides --- concurrent consumers
        vector<Driver>drivers;
        mutex mtx; //shared driver data
        condition_variable cv; //make threads wait if no driver is free
        DriverManager(){
            drivers.emplace_back(101, Location(1,1));
            drivers.emplace_back(101, Location(1,1));
            drivers.emplace_back(101, Location(1,1));
        }
        Driver* findNearestDriver(const Location& userLoc){
            //get closest driver or wait until avialaility
            unique_lock<mutex>lock(mtx);
            cv.wait(//internal loop
                lock,
                [&](){
                    for(auto& d:drivers){
                    if(d.available)return true;
                    }
                    return false;
                }
            );
            /*
            while(predicate()==false){
            unlock(mutex);
            sleep();
            lock(mutex)}
            */
            Driver* best=nullptr;
            double minDist=1e9;
            for(auto& d: drivers){
                if(d.available){
                    double dist=d.loc.distance(userLoc);
                    if(dist<minDist){
                        minDist=dist;
                        best=&d;
                    }
                }                
            }
            //mark driver busy
            best->available=false;
            return best;
        }
        void releaseDriver(
            Driver* driver
        ){
            lock_guard<mutex>lock(mtx);//single thread can access acquire
            driver-> available=true;
            cv.notify_one();
        }
    };
    class PaymentService{
        public:
        atomic<int>totalEarnings{0};///multiple threads are updating this shared variables
        void pay(int amount){
            this_thread::sleep_for(chrono::milliseconds(1000));
            totalEarnings.fetch_add(amount);
        }

    };
    class NotificationService{
        public:
        void send(int rideId){
            this_thread::sleep_for(chrono::milliseconds(100));
            cout<<"Notified to ride"<<endl<<rideId<<endl<<endl;
        }
    };//Thread Pool
    class ThreadPool{
        vector<thread>workers;
        queue<function<void()>>tasks;
        mutex mtx;
        condition_variable cv;
        bool stop=false;
        public:
        ThreadPool(int n){
            for(int i=0;i<n;i++){
                workers.emplace_back([this](){
                    while(true){
                        function<void()>task;
                        ///if no task in hand and running, just shut up at the corner
                        {
                        unique_lock<mutex>lock(mtx);
                        cv.wait(lock, [&](){
                            return stop||!tasks.empty();
                        });//mutex unlock, thread waiting, cpu free
                        if(stop&&tasks.empty())return;
                        task=move(tasks.front());//thread access single task only, move ownershiip no copy
                        // tasks queue ──> empty
                        // task local var ──> callable
                        tasks.pop();
                        }
                    task();

                    }
                });
            }
        }
        void submit(function<void()>task){
            {
                lock_guard<mutex>lock(mtx);
                tasks.push(task);
            }
            cv.notify_one();//thread ko jagade bhai
        }
        ~ThreadPool(){
            {
                lock_guard<mutex>lock(mtx);
                stop=true;
            }
            cv.notify_all();
            //exit honeka time agaya hai threads ka
            for(auto& t:workers){
                t.join();
            }

        }

    };
    class RideService{
        public:
        DriverManager& dm;
        PaymentService& pm;
        NotificationService notifier;
        RideService(DriverManager &d , PaymentService &p):dm(d),pm(p){}
            // this->d=dm; 
            // this->p=pm;

        
        void bookRide(int rideId, Location userloc){
            cout<<"Ride Request"<<rideId<<rideId<<endl;
            Driver* driver=dm.findNearestDriver(userloc);
            cout<<"Driver"<<driver->id<<"assigned to the ride"<<rideId<<endl;
            pm.pay(300);
            auto notifyFuture=async(
                launch::async,
                &NotificationService::send,
                &notifier,
                rideId
            );///created the future, new Thread Spawned, work in background result after work done in future
            this_thread::sleep_for(chrono::milliseconds(5000));
            dm.releaseDriver(driver);
            notifyFuture.get();
            cout<<"ride"<<rideId<<"completed"<<endl;
        }

    };


int main(){
    DriverManager dm;
    PaymentService pm;
    ThreadPool pool(4);
    RideService rds(dm,pm);
    for(int i=1;i<=8;i++){
        pool.submit([&, i](){
            rds.bookRide(i, Location(i,i));
        });
    }
    this_thread::sleep_for(chrono::seconds(3));
    cout<<"Total Earneings"<<endl<<pm.totalEarnings.load()<<endl;
    return 0;
}

