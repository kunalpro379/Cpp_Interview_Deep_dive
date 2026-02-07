#include <queue>
#include <iostream>
using namespace std;
int main(){
    // Default: Max-heap (largest at top)
priority_queue<int> pq1;

// Min-heap
priority_queue<int, vector<int>, greater<int>> pq2;

// From existing vector
vector<int> v = {3,1,4,1,5};
priority_queue<int> pq3(v.begin(), v.end());

// Custom comparator
struct Compare {
    bool operator()(int a, int b) {
        // For min-heap based on custom logic
        return a > b; // '>' for min-heap, '<' for max-heap
    }
};
priority_queue<int, vector<int>, Compare> pq4;

// For pairs (min-heap based on first element)
priority_queue<pair<int,int>, vector<pair<int,int>>, 
               greater<pair<int,int>>> pq5;
    
               priority_queue<int> pq;

// 1. push() - Insert element
pq.push(10);                    // O(log n)
pq.push(20);
pq.push(5);

// 2. top() - Access top (max for max-heap)
cout << pq.top();               // 20, O(1)

// 3. pop() - Remove top
pq.pop();                       // O(log n), now top=10

// 4. size() - Number of elements
cout << pq.size();              // O(1)

// 5. empty() - Check if empty
if(pq.empty()) {}               // O(1)

// NO ITERATION! Cannot traverse heap directly
// NO clear() method! Use: while(!pq.empty()) pq.pop();
// 1. K largest elements
vector<int> findKLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(int num : nums) {
        minHeap.push(num);
        if(minHeap.size() > k) minHeap.pop();
    }
    // minHeap contains k largest elements
}

// 2. Median of stream
class MedianFinder {
    priority_queue<int> maxHeap; // lower half
    priority_queue<int, vector<int>, greater<int>> minHeap; // upper half
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        
        if(maxHeap.size() < minHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
};

// 3. Task scheduler
struct Task {
    int priority;
    string name;
};
auto cmp = [](Task a, Task b) { return a.priority < b.priority; };
priority_queue<Task, vector<Task>, decltype(cmp)> taskQueue(cmp);
/*
Max-Heap:         20
                 /  \
                15   10
               /  \
              5    7
Array: [20, 15, 10, 5, 7]
Index:  0   1   2   3  4

Children of i: 2i+1, 2i+2
Parent of i: (i-1)/2
*/
}