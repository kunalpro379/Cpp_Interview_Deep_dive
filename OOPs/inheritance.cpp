#include <iostream>
using namespace std;

class Parent {
public:
    int p = 10;

    void normal() {
        cout << "Parent normal()\n";
    }

    virtual void virt() {
        cout << "Parent virt()\n";
    }
};

class Child : public Parent {
public:
    int c = 20;

    void normal() {
        cout << "Child normal()\n";
    }

    void virt() override {
        cout << "Child virt()\n";
    }

    void childOnly() {
        cout << "Child only(), c = " << c << endl;
    }
};

int main(){
    Child c;
    Child* cp=&c;
    cp->normal();
    cp->virt();
    cp->childOnly();
    //no confusion everything of child;


    //child object parent pointer (UPcasting)
    Child c;
    Parent *pp=&c;
    pp->normal();
    pp->virt();//in run time vtable decided object actually me child hai

    //Parent object parent pointer
    Parent p;
    Parent * pp=&p;
    pp->normal();
    pp->virt();//object hi parent hain
}