#include <unordered_map>
#include <iostream>
using namespace std;
int main(){
    unordered_map<int, string> um1;                      // Empty
unordered_map<int, string> um2 = {{1,"A"}, {2,"B"}};
unordered_map<int, string> um3(um2);                 // Copy

// With initial bucket count
unordered_map<int, string> um4(100);                 // 100 buckets

// With hash function and equality
struct MyHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ hash<int>()(p.second);
    }
};
unordered_map<pair<int,int>, string, MyHash> um5;

// Custom equality for complex keys
struct MyEqual {
    bool operator()(const pair<int,int>& a, 
                   const pair<int,int>& b) const {
        return a.first == b.first && a.second == b.second;
    }
};
unordered_map<int, string> um = {{1, "one"}, {2, "two"}};

// 1. operator[] - Access or insert
um[3] = "three";         // Creates if not exists, O(1) avg
cout << um[1];           // "one", O(1) avg

// 2. at() - Safe access
cout << um.at(2);        // "two", throws if not found

// 3. find() - Iterator to element
auto it = um.find(2);    // O(1) avg, end() if not found

// 4. count() - Check existence  
if(um.count(2) == 1) {   // Always 0 or 1, O(1) avg
    cout << "Exists";
}


unordered_map<int, string> um;

// 1. insert()
um.insert({1, "apple"});            // O(1) avg
auto res = um.insert({1, "avocado"}); // Fails, key exists

// 2. emplace()
um.emplace(2, "banana");            // O(1) avg

// 3. erase()
um.erase(1);                        // By key, O(1) avg
um.erase(um.find(2));               // By iterator, O(1) avg
um.erase(um.begin(), um.end());     // By range, O(n)

// 4. clear()
um.clear();                         // O(n)

// 5. rehash() - Change bucket count
um.rehash(1000);                    // O(n), rehashes all

// 6. reserve() - Set minimum buckets
um.reserve(1000);                   // O(n), prevents rehashes


unordered_map<int, string> um = {{1,"A"}, {2,"B"}, {3,"C"}};

// 1. bucket_count() - Total buckets
cout << um.bucket_count();          // Prime number like 7

// 2. bucket(key) - Which bucket key is in
int bucket_num = um.bucket(1);      // O(1) avg

// 3. bucket_size(n) - Elements in bucket n
for(size_t i=0; i<um.bucket_count(); ++i) {
    cout << "Bucket " << i << ": " << um.bucket_size(i) << " elements";
}

// 4. begin(n), end(n) - Iterate specific bucket
for(auto it = um.begin(2); it != um.end(2); ++it) {
    cout << it->first << ": " << it->second;
}



unordered_map<int, string> um;

// 1. load_factor() - Elements per bucket average
float lf = um.load_factor();        // size()/bucket_count()

// 2. max_load_factor() - Get/set max load factor
float mlf = um.max_load_factor();   // Default 1.0
um.max_load_factor(0.75);           // Rehash when > 0.75

// 3. rehash() - Explicit rehash
um.rehash(100);                     // Sets bucket count >= 100

// 4. reserve() - For expected elements
um.reserve(1000);                   // Sets buckets for 1000 elements


unordered_map<int, string> um = {{3,"C"}, {1,"A"}, {2,"B"}};

for(auto& [key, val] : um) {
    cout << key << ": " << val;  // Random order! Could be 1,3,2 or 2,1,3
}

// Same methods as map: begin(), end(), rbegin(), rend()

/*
Buckets:    [0] → NULL
           [1] → Node(1,"A") → Node(8,"H") → NULL  
           [2] → Node(2,"B") → NULL
           [3] → NULL
           ...
hash(1) = 1, hash(8) = 1  (collision, chaining)

Load factor = elements/buckets
When load_factor > max_load_factor, rehash:
1. Create new bucket array (usually ~2x size)
2. Rehash all elements
3. Update pointers
*/

}