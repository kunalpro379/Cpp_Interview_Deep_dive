#include <queue>
#include <iostream>
using namespace std;
int main(){
    queue<int> q;

// 1. push() - Add to back
q.push(10);                     // O(1)
q.push(20);
q.push(30);

// 2. front() - Access front element
cout << q.front();              // 10, O(1)

// 3. back() - Access back element  
cout << q.back();               // 30, O(1)

// 4. pop() - Remove front (returns void)
q.pop();                        // O(1), now front=20

// 5. size() - Number of elements
cout << q.size();               // 2, O(1)

// 6. empty() - Check if empty
if(q.empty()) {}                // O(1)

// NO ITERATION! Can't traverse queue


}