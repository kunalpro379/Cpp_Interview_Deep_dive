#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;   
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 25, 30, 45, 50};
    int key = 30;

    int index = linearSearch(arr, key);

    if (index != -1)
        cout << "Element found at index: " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}