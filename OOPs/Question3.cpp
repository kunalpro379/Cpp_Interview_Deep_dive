// Difference between Pointer and Reference in C++
// Pointer → variable holding an address
// Reference → alias (another name) for the same memory
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;

    int* p = &a;   // pointer
    int& r = a;    // reference

    cout << *p << " " << r << endl; // 10 10

    p = &b;        // allowed
    // r = b;      // this assigns b to a

    cout << *p << " " << r << endl; // 20 20 (a changed!)


    int arr [] = {10, 20, 30};
    int* ptr = arr;
    cout <<*(ptr + 1)<<" "<<*(ptr + 2) <<endl<<*(ptr + 5) <<endl;

    
    return 0;
}


//Struct and class behavious are aidentical 
// but struct is public by default and class is private by default
// struct data centric 
// class behavior centric
// Use struct for passive data, class for invariants + behavior

//Pass by Value vs Pointer vs Reference
void change(int x) {//coppy created, slower for large objects
    x = 100;
}
// Pass by Pointer
void change(int* x) {//can be nullptr, requiring dereferencing
    *x = 100;
}

//pass by reference
void change(int& x) {
    x = 100;
}