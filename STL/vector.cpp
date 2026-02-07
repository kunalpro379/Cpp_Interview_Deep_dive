#include <vector>
#include <iostream>
using namespace std;
int main(){
vector<int> v1;                    // Empty vector
vector<int> v2(5);                 // 5 elements, value = 0
vector<int> v3(5, 100);            // 5 elements, all = 100
vector<int> v4 = {1, 2, 3, 4, 5};  // Initializer list
vector<int> v5(v4);                // Copy constructor
vector<int> v6(v4.begin(), v4.begin()+3); // From iterators
vector<int> v = {10, 20, 30, 40, 50};

// 1. operator[] - Fast, no bounds checking
cout << v[2];      // 30, O(1),  No exception if out of bounds

// 2. at() - Safe, with bounds checking  
cout << v.at(2);   // 30, O(1),  Throws std::out_of_range

// 3. front() - First element
cout << v.front(); // 10, O(1)

// 4. back() - Last element  
cout << v.back();  // 50, O(1)

// 5. data() - Raw pointer to underlying array
int* ptr = v.data(); // Points to first element, O(1)
vector<int> v = {1, 2, 3};

// 1. push_back() - Add to end
v.push_back(4);      // v = {1,2,3,4}, O(1)* amortized
// *Amortized means average O(1), occasionally O(n) when resizing

// 2. pop_back() - Remove from end
v.pop_back();        // v = {1,2,3}, O(1)

// 3. insert() - Insert at position
v.insert(v.begin() + 1, 99); // v = {1,99,2,3}, O(n)

// Insert multiple copies
v.insert(v.begin(), 3, 5); // Insert three 5s at start

// 4. erase() - Remove element(s)
v.erase(v.begin() + 1);     // Remove element at position 1, O(n)
v.erase(v.begin(), v.begin()+2); // Remove first 2 elements

// 5. emplace_back() - Construct in-place (C++11)
v.emplace_back(100); // More efficient than push_back for objects
// push_back creates temporary then copies, emplace_back constructs directly

// 6. clear() - Remove all elements
v.clear();           // v = {}, O(n)

// 7. resize() - Change size
v.resize(10);        // Size=10, new elements=0, O(n)
v.resize(3);         // Truncate to 3 elements
v.resize(8, 100);    // New elements initialized to 100

// 8. swap() - Exchange contents
vector<int> v2 = {9,8,7};
v.swap(v2);          // v={9,8,7}, v2={1,2,3}, O(1)

vector<int> v;

// 1. size() - Current number of elements
cout << v.size();    // O(1)

// 2. capacity() - Current allocated storage
cout << v.capacity(); // O(1), >= size()

// 3. empty() - Check if vector is empty  
if(v.empty()) {}     // O(1)

// 4. reserve() - Pre-allocate memory (NO initialization)
v.reserve(1000);     // Allocate memory for 1000 elements, O(n) if reallocation

// 5. shrink_to_fit() - Reduce capacity to fit size
v.shrink_to_fit();   // O(n), may or may not reduce capacity

// 6. max_size() - Maximum possible elements
cout << v.max_size(); // O(1), very large number

vector<int> v = {1, 2, 3, 4, 5};

// 1. begin() - Iterator to first element
auto it1 = v.begin();     // Points to 1

// 2. end() - Iterator to AFTER last element  
auto it2 = v.end();       // Points past 5

// 3. rbegin() - Reverse iterator (from end)
auto rit = v.rbegin();    // Points to 5

// 4. rend() - Reverse end iterator
auto rit_end = v.rend();  // Points before 1

// 5. cbegin(), cend() - Const iterators
auto cit = v.cbegin();    // Can't modify through this

// Iteration examples:
for(auto it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
}

for(int val : v) {        // Range-based for loop
    cout << val << " ";
}

for(auto rit = v.rbegin(); rit != v.rend(); ++rit) {
    cout << *rit << " ";  // Reverse iteration
}

#include <algorithm>
vector<int> v = {5, 2, 8, 1, 9};

// 1. sort()
sort(v.begin(), v.end());      // Ascending, O(n log n)
sort(v.rbegin(), v.rend());    // Descending

// 2. find()
auto it = find(v.begin(), v.end(), 8); // O(n)

// 3. binary_search() - Must be sorted
bool found = binary_search(v.begin(), v.end(), 5); // O(log n)

// 4. lower_bound() - First element >= value
auto lb = lower_bound(v.begin(), v.end(), 5); // O(log n)

// 5. upper_bound() - First element > value
auto ub = upper_bound(v.begin(), v.end(), 5); // O(log n)

// 6. reverse()
reverse(v.begin(), v.end());   // O(n)

// 7. accumulate() - Sum of elements
#include <numeric>
int sum = accumulate(v.begin(), v.end(), 0); // O(n)

/*
SPACE COMPLEXITY: O(n)
Only stores elements, no extra pointers

May have some unused capacity (capacity ≥ size)

Initially: capacity=0, size=0
push_back(1): allocate 1, size=1, capacity=1
push_back(2): allocate 2, copy old, size=2, capacity=2  
push_back(3): allocate 4, copy old, size=3, capacity=4
push_back(4): size=4, capacity=4
push_back(5): allocate 8, copy old, size=5, capacity=8
// Typically doubles capacity when needed
*/

int arr[5] = {1, 2, 3, 4, 5};  // Size fixed at compile time
// No size() method, use sizeof(arr)/sizeof(arr[0])
#include <array>
array<int, 5> arr = {1, 2, 3, 4, 5};

// Methods similar to vector (except no push/pop)
arr.size();      // 5, O(1)
arr.fill(10);    // All elements = 10
arr.at(2);       // Bounds checked
arr.front();     // First element
arr.back();      // Last element
arr.data();      // Raw pointer

}