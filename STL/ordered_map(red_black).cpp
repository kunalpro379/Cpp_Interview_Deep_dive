#include <map>
#include <iostream>
using namespace std;

/*Ordered Map RedBlack Tree*/
/*
Need key-value pairs SORTED by key
Need ordered traversal
Need lower_bound/upper_bound operations
When key comparisons are meaningful
*/
int main(){
map<int, string> m1;                         // Empty
map<int, string> m2 = {{1, "Alice"}, {2, "Bob"}};
map<int, string> m3(m2);                     // Copy
map<int, string> m4(m2.begin(), m2.end());   // From iterators

// With custom comparator
struct Compare {
    bool operator()(const string& a, const string& b) const {
        return a.length() < b.length(); // Sort by length
    }
};
map<string, int, Compare> m5;


map<int, string> m = {{1, "one"}, {2, "two"}};

// 1. operator[] - Access or insert
m[3] = "three";      // Creates key 3 if doesn't exist
cout << m[1];        // "one", O(log n)

// 2. at() - Access with bounds check
cout << m.at(2);     // "two", O(log n), throws if key not found

// 3. find() - Returns iterator
auto it = m.find(2); // O(log n), returns m.end() if not found
if(it != m.end()) {
    cout << it->first << ": " << it->second;
}

// 4. count() - Check existence
if(m.count(2) > 0) { // Returns 0 or 1 (unique keys), O(log n)
    cout << "Key exists";
}


map<int, string> m;

// 1. insert() - Insert key-value
m.insert({1, "apple"});               // O(log n)
m.insert(make_pair(2, "banana"));
m.insert(pair<int, string>(3, "cherry"));

auto result = m.insert({1, "avocado"}); 
// result.second = false (failed, key exists)
// result.first = iterator to existing element

// 2. emplace() - Construct in-place
m.emplace(4, "date");                 // O(log n)
// More efficient: constructs pair in map memory

// 3. emplace_hint() - Insert with hint
auto hint = m.find(3);
m.emplace_hint(hint, 5, "elderberry"); // O(1) if hint is correct

// 4. erase() - Remove elements
m.erase(2);                           // By key, O(log n)
m.erase(m.find(3));                   // By iterator, O(1) amortized
m.erase(m.begin(), m.find(4));        // By range

// 5. clear() - Remove all
m.clear();                            // O(n)

// 6. swap() - Exchange
map<int, string> m2;
m.swap(m2);                           // O(1)



map<int, string> m = {{3, "three"}, {1, "one"}, {2, "two"}};

// Traversal is IN ORDER (sorted by key)
for(auto it = m.begin(); it != m.end(); ++it) {
    cout << it->first << ": " << it->second << endl;
}
// Output: 1: one, 2: two, 3: three (sorted!)

// Reverse iteration
for(auto rit = m.rbegin(); rit != m.rend(); ++rit) {
    cout << rit->first << ": " << rit->second;
}

// C++17 structured binding
for(auto& [key, value] : m) {
    cout << key << ": " << value;
}


map<int, string> m = {{10, "A"}, {20, "B"}, {30, "C"}, {40, "D"}};

// 1. lower_bound(k) - First element >= k
auto lb = m.lower_bound(25); // Points to 30, O(log n)

// 2. upper_bound(k) - First element > k  
auto ub = m.upper_bound(25); // Points to 30, O(log n)
auto ub2 = m.upper_bound(30); // Points to 40

// 3. equal_range(k) - Returns pair<lb, ub>
auto range = m.equal_range(20); // [20, 30)
// range.first points to 20, range.second points to 30

// 4. find elements in range
auto it_low = m.lower_bound(15);
auto it_high = m.upper_bound(35);
for(auto it = it_low; it != it_high; ++it) {
    cout << it->first << " "; // 20, 30
}


map<int, string> m;

m.empty();      // O(1), check if empty
m.size();       // O(1), number of elements
m.max_size();   // O(1), maximum possible elements

// Get comparator object
auto comp = m.key_comp();    // Compare keys
auto comp_val = m.value_comp(); // Compare pairs
/*
        B20
       /    \
     R10    R30
            /  \
          B25  B40
Properties:
1. Root is black
2. Red nodes have black children  
3. Equal black nodes on all paths
4. Self-balancing (height ~ 2*log(n))
*/

}
