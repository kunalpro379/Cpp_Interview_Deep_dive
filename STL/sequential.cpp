#include<iostream>
using namespace std;
#include<deque>
#include<array>
#include<vector>
//Sequence Containers
/*
std::array
std::vector
std::deque
std::list
std::forward_list
What is std::array
*/
int main(){
/*
Wrapper over C-style array
Size is fixed at compile time
Stored on stack (usually)
No dynamic resizing
*/

    array<int, 5> arr = {1, 2, 3, 4, 5};

    cout << arr.at(3) << endl;        // O(1)
    cout << arr.front() << endl;      // O(1)
    cout << arr.back() << endl;       // O(1)
    cout << arr.size() << endl;       // O(1)
    cout << arr.empty() << endl;      // O(1)
    cout << arr.data() << endl;       // address

    arr.fill(10);                     // O(n)
    for (int x : arr)
        cout << x << " ";
    cout << endl << endl;
    for (auto it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
 

    vector<int> vec = {1, 2, 3, 4, 5};

    cout << vec.at(3) << endl;        // O(1)
    cout << vec.front() << endl;      // O(1)
    cout << vec.back() << endl;       // O(1)
    cout << vec.size() << endl;       // O(1)
    cout << vec.capacity() << endl;
    cout << vec.empty() << endl;

    vec.push_back(6);                 // amortized O(1)
    vec.pop_back();                   // O(1)

    vec.insert(vec.begin() + 2, 99);  // O(n)
    vec.erase(vec.begin() + 2);       // O(n)

    vec.reserve(20);                  // O(n)
    vec.shrink_to_fit();              // O(n)

    vec.assign(3, 7);                 // O(n)

    for (int x : vec)
        cout << x << " ";
    cout << endl << endl;


/*
std::deque (Double Ended Queue)
What is std::deque
Dynamic sequence container
Allows fast insertion/deltion at BOTH ends
Not fully contiguous like vector
Implemented as multiple memory blocks
*/
    deque<int> dq = {10, 20, 30};

    cout << dq.front() << endl;       // O(1)
    cout << dq.back() << endl;        // O(1)
    cout << dq.at(1) << endl;         // O(1)

    dq.push_back(40);                 // O(1)
    dq.push_front(5);                 // O(1)

    dq.pop_back();                    // O(1)
    dq.pop_front();                   // O(1)

    dq.insert(dq.begin() + 1, 15);    // O(n)
    dq.erase(dq.begin() + 1);         // O(n)

    dq.resize(5, 100);                // O(n)

    for (int x : dq)
        cout << x << " ";
    cout << endl;

    vector<int> a = {1, 2, 3};
    vector<int> b = {10, 20};
    a.swap(b);         // O(1)
    for (int x : a) cout << x << " ";
    for (int x : b) cout << x << " ";
    vec.resize(6, 100);  // increase → O(n)
    vec.resize(3);       // decrease → O(n)
    return 0;
}