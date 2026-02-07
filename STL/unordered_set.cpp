#include <unordered_set>
#include <iostream>
using namespace std;
int main(){
    unordered_set<int> us = {3, 1, 4, 1, 5}; // {1,3,4,5} - unique, unordered

// Insert
us.insert(2);                    // O(1) avg

// Find  
auto it = us.find(3);            // O(1) avg

// Check existence
if(us.count(5) > 0) {}           // O(1) avg

// Erase
us.erase(4);                     // O(1) avg

// Bucket interface (same as unordered_map)
us.bucket_count();
us.load_factor();


}