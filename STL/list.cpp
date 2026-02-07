#include <list>
#include <iostream>
using namespace std;
int main(){
    list<int> li = {1, 2, 3, 4};

// INSERTION
li.push_front(0);               // {0,1,2,3,4}, O(1)
li.push_back(5);                // {0,1,2,3,4,5}, O(1)

auto it = li.begin();
advance(it, 2);                 // Points to 2
li.insert(it, 99);              // {0,1,99,2,3,4,5}, O(1)

// DELETION
li.pop_front();                 // {1,99,2,3,4,5}, O(1)
li.pop_back();                  // {1,99,2,3,4}, O(1)

li.remove(99);                  // Remove all 99s, O(n)
li.erase(li.begin());           // Remove first, O(1)

// SPECIAL OPERATIONS
list<int> li2 = {10, 20, 30};
auto it2 = li.begin();
advance(it2, 2);
li.splice(it2, li2);            // Merge lists, O(1)
// li = {1, 2, 10, 20, 30, 3, 4}, li2 = {}

li.sort();                      // O(n log n), stable sort
li.unique();                    // Remove consecutive duplicates, O(n)
li.reverse();                   // O(n)
li.merge(li2);                  // Merge sorted lists, O(n)

// SIZE
li.resize(10);                  // O(n)
li.clear();                     // O(n)


}