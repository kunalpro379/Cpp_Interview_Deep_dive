// Q1. Can we overload functions using int vs const int?
#include <iostream>
using namespace std;

void process(int& x) {
    cout << "modifiable reference\n";
}

void process(const int& x) {
    cout << "read-only reference\n"<<x+1<<endl;
}

int main() {
    int a = 10;
    const int b = 20;

    process(a); // modifiable reference
    process(b); // const reference
}

