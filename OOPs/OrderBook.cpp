// Entity Order----> Implementations (OrderBook, buybook, sellbook)----> interface(abstraction)(Iorderbook, addOrder, printTop5())
#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<memory>
using namespace std;
enum class OrderType{
    BUY, SELL
};
class Order{
    private:
    int orderId;
    static int globalId;
    OrderType type;
    double price;
    int quantity;
    public:
    Order(
        OrderType type, double price, int quatity
    ){
        this->type=type;
        this->price=price;
        this-> quantity=quatity;
        orderId=++globalId;
    }
    double getprice() const{
        return price;
    }
    int getQuantity() const{
        return quantity;
    }
    OrderType getType()const {
        return type;
    }
    int getId()const {
        return orderId;
    }
};
int Order::globalId=0;

class IOrderBook{
    public:
    virtual void addOrder(const Order& order)=0;
    virtual void printTop5()=0;
    virtual ~IOrderBook()=default;
};
class OrderBook:public IOrderBook{
    private:
    static map<double, vector<Order>, greater<double>>buyBook;
    static map<double, vector<Order>>sellBook;
    template <typename T>
    void Print(const T& book)const {
        int count=0;
        for(const auto&[price, orders]:book){
            for(const auto& o:orders){
                cout<<"ID : "<<o.getId()<<"----"<<"price : "<<price<<"----"<<"Quantity : "<<o.getQuantity()<<endl;
            }
        }
        if(count==0)return;
    }
    public:
    void addOrder(
        const Order& order
    ){
        if(order.getType()==OrderType::BUY){
            buyBook[order.getprice()].push_back(order);
        }else{
            sellBook[order.getprice()].push_back(order);

        }
        printTop5();
    }
    void printTop5(){
        cout<<"____________________________________________"<<endl<<"Top buy Orders"<<endl;
        Print(buyBook);
        cout<<"____________________________________________"<<"Top sell Orders"<<endl;
        Print(sellBook);
        cout<<"____________________________________________"<<endl;

    }
    
};
// static storage;
 map<double, vector<Order>, greater<double>>OrderBook::buyBook;
 map<double, vector<Order>>OrderBook::sellBook;


int main(){
    unique_ptr<IOrderBook>book=make_unique<OrderBook>();
    book->addOrder(Order(OrderType::BUY, 100, 10));
    book->addOrder(Order(OrderType::SELL, 99, 5));
    book->addOrder(Order(OrderType::BUY, 105, 3));
    book->addOrder(Order(OrderType::BUY, 1034, 10));
    book->addOrder(Order(OrderType::SELL, 992, 5));
    book->addOrder(Order(OrderType::BUY, 100.5, 10));
    book->addOrder(Order(OrderType::BUY, 101.0, 5));
    book->addOrder(Order(OrderType::SELL, 102.0, 7));
    book->addOrder(Order(OrderType::SELL, 99.5, 12));
    book->addOrder(Order(OrderType::BUY, 103.2, 3));
    book->addOrder(Order(OrderType::SELL, 98.0, 8));
    return 0;
}