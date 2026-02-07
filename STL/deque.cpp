#include <deque>
#include <iostream>
using namespace std;
int main(){
    deque<int> dq = {1, 2, 3};

// FRONT OPERATIONS
dq.push_front(0);               // {0,1,2,3}, O(1)
dq.pop_front();                 // {1,2,3}, O(1)
cout << dq.front();             // 1, O(1)

// BACK OPERATIONS  
dq.push_back(4);                // {1,2,3,4}, O(1)
dq.pop_back();                  // {1,2,3}, O(1)
cout << dq.back();              // 3, O(1)

// RANDOM ACCESS (UNIQUE!)
cout << dq[1];                  // 2, O(1)
cout << dq.at(2);               // 3, O(1) with bounds check

// MIDDLE OPERATIONS
dq.insert(dq.begin() + 1, 99);  // {1,99,2,3}, O(n)
dq.erase(dq.begin() + 2);       // {1,99,3}, O(n)

// ITERATION (YES!)
for(auto it = dq.begin(); it != dq.end(); ++it) {
    cout << *it << " ";
}

// SIZE
dq.resize(10);                  // O(n)
dq.shrink_to_fit();             // O(n)
}