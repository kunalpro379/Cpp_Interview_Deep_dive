#include <set>
#include <iostream>
using namespace std;

int main(){
    set<int> s = {3, 1, 4, 1, 5, 9}; // {1, 3, 4, 5, 9} - sorted, unique

// Insert
s.insert(2);                    // O(log n)
auto res = s.insert(3);         // Fails, already exists

// Find
auto it = s.find(4);            // O(log n)
if(it != s.end()) cout << *it;

// Check existence
if(s.count(5) > 0) {}           // O(log n)

// Erase
s.erase(4);                     // O(log n)

// Set operations (require sorted ranges)
set<int> s1 = {1, 2, 3};
set<int> s2 = {2, 3, 4};
vector<int> result;

// Union
set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), 
          back_inserter(result));

// Intersection  
set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                 back_inserter(result));

// Difference
set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(),
               back_inserter(result));

               
}