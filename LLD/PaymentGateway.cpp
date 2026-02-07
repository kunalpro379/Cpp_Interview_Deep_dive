#include <iostream>
#include <string>
#include <memory>
#include <mutex>
#include <vector>
#include <atomic>
#include <unordered_map>
#include <functional>
#include <thread>

using namespace std;
enum class PaymentType{
    UPI,CREDIT_CARD, DEBIT_CARD, COD
};
enum class TransactionStatus{
    CREATED, PROCESSING, SUCCESS, FAILED, REDUNDED
};
//Strategy--Payment abstraction 
class IpaymentMethod{
    public:
    virtual ~IpaymentMethod()=default;
    void execute(double amount){
        validate(amount);
        process(amount);
        confirm(amount);
    }
    protected:
    virtual void validate(double amount)=0;
    virtual void process(double amount)=0;
    virtual void confirm(double amount)=0;
    
};
class IRefundable{
    public:
    virtual ~IRefundable()=default;
    virtual void refund(double amount)=0;
};
class UPIPayment:public IRefundable, public IpaymentMethod{};
class CreditCardPayment:public IRefundable, public IpaymentMethod{};
class DebitCardPayment:public IRefundable, public IpaymentMethod{};
class CashOnDelivery:public IpaymentMethod{};
class PaymentFactory{};
class Transaction{};
class TransactionIdGenerator{};
class TransactionReponsitory{};
class CircuitBreaker{};
class RetryHandler{};
class PaymentCommand{};
class PaymentGateway{};
class PaymentProcessing{};
int main(){

}