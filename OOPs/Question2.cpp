// Q2. What exactly does volatile do?

// volatile makes code thread-safe  ---> wrong
// variables value can change at any time

#include <iostream>
#include<vector>
using namespace std;

bool flag = false;

void wait() {
    while (!flag) {
        // do nothing
    }
    cout << "Done\n";
}
volatile bool flagvolatile=false;
void waitvolatile() {
    while (!flagvolatile) {
        // do nothing
    }
    cout << "Done\n";
}


int & counter(){///function willl return the reference to the count return var
    //returning the actual var not a copy
    static int count=0;
    return count;
}
auto x = 10;// int
auto y = 3.14; // double
auto z = 'A'; // char
auto s = "hello";// const char*
// auto x; // ERROR it needs initializer
// auto drops const and reference
// so we use auto&  to Preserve reference
int a = 10;
const int b = 20;
auto& r1 = a;   // int&
auto& r2 = b;   // const int&
vector<int> v = {1,2,3};
// for (auto x : v){cout<<x;}// copy
// for (auto& x : v)// reference
// for (const auto& x : v)
auto sum(int a, int b) {
    return a + b; //
}//correct
/*
auto& sum(int a, int b) {
    return a + b; //
}//ERROR
*/ 
//   because
// You are trying to return a reference to a temporary value.
// return reference_to_temporary;
/*a+b :-
Produces a temporary rvalue
Stored nowhere
Destroyed immediately after return
*/

int main(){
    //  wait();//flag never changes  so while(true) infintely running 

    //now compiler will force to re read the flag from memory every time 
    // it prevents compiler caching, its not a thread safe
// volatile ≠ thread safety
// atomic = thread safety

    // waitvolatile();
    // Function returns reference
    auto x = counter();   // COPY
    auto& y = counter();  // REFERENCE
    x++;  // modifies local copy
    y++;  // modifies static variable
    cout << counter(); // prints 1, not 2

    int m = 5;
    cout<<(++m) + (m++) <<endl;
    return 0;

}