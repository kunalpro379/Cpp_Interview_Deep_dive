#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "I am Base\n";
    }

    virtual ~Base() {}   // IMPORTANT for dynamic_cast
};

class Derived : public Base {
public:
    void show() override {
        cout << "I am Derived\n";
    }

    void derivedOnly() {
        cout << "Derived specific function\n";
    }
};
int main(){
/*
    //Upcasting

    // b base pointer hai and  derived is a base and derived object ko point kar raha hain base gurenteed exists
    Derived d;
    Base* b=&d;
    b->show();

    //down casting  dangerous 
    Base* b = new Base();
    Derived* d=(Derived*) b; 
    // we are telling compilter that b is a derived but in reality base missing derived 

    b (Base*)    = 0x1000
    d (Derived*) = 0x1000   ← SAME ADDRESS
    */
   //Downcasting using static cast (UNSAFE)
   /*
   Base* b=new Derived();
   Derived * d=static_cast<Derived*>(b);
    
   d->derivedOnly(); ERROR
*/
   //Downcasting using dynamic cast(SAFE)
    Base* b=new Derived();
    Derived* d=dynamic_cast<Derived*>(b);
    if(d){
        d->derivedOnly();
    }//return nullptr if cast fails



}