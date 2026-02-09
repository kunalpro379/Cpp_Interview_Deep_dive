#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
using namespace std;
constexpr size_t CACHE_LINE = 64;
class Order{
    protected:
    int orderId;
    double price;
    public:
    Order(int id, double price){
        this->orderId=id;
        this->price=price;
    }
    virtual ~Order(){}
    virtual void execute()=0;
    virtual double value() const=0;
    friend class RiskManager;
};
