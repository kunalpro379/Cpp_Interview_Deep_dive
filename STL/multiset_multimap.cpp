#include <set>
#include<iostream>
#include <map>

using namespace std;
int main(){
multiset<int> ms = {1, 2, 2, 3, 3, 3};

ms.insert(2);                   // Now has four 2s, O(log n)
cout << ms.count(3);            // 3, O(log n + k)

// Erase all 2s
ms.erase(2);                    // Removes ALL 2s, O(log n + k)

// Erase one 2
auto it = ms.find(2);
if(it != ms.end()) ms.erase(it); // Remove only one, O(log n)

// equal_range() useful
auto range = ms.equal_range(3); // All 3s, O(log n)
for(auto it = range.first; it != range.second; ++it) {
    cout << *it << " ";         // Prints all 3s
}
multimap<int, string> mm = {{1,"A"}, {1,"B"}, {2,"C"}};

mm.insert({1, "D"});            // OK, multiple keys=1 allowed
// NO operator[]! Can't use mm[1] = "E";

// Find all values for key=1
auto range = mm.equal_range(1);
for(auto it = range.first; it != range.second; ++it) {
    cout << it->second << " ";  // A, B, D
}
}