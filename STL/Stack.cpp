#include <stack>
#include <iostream>
using namespace std;
int main(){
    stack<int> st;

// 1. push() - Add to top
st.push(10);                    // O(1)
st.push(20);
st.push(30);

// 2. top() - Access top element
cout << st.top();               // 30, O(1)

// 3. pop() - Remove top (returns void)
st.pop();                       // O(1), now top=20

// 4. size() - Number of elements
cout << st.size();              // 2, O(1)

// 5. empty() - Check if empty
if(st.empty()) {}               // O(1)

// NO ITERATION! Can't traverse stack
// NO clear() method
// 1. Balanced parentheses
bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if(st.empty()) return false;
            char top = st.top(); st.pop();
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) return false;
        }
    }
    return st.empty();
}

// 2. Next greater element
vector<int> nextGreater(vector<int>& nums) {
    stack<int> st;
    vector<int> result(nums.size(), -1);
    for(int i = 0; i < nums.size(); i++) {
        while(!st.empty() && nums[st.top()] < nums[i]) {
            result[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}

}
