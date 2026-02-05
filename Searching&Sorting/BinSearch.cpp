#include<iostream>
#include<vector>
using namespace std;
int binsearch(const vector<int>&vec, int target){
    int low=0, high=vec.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(vec[mid]==target)return mid;
        else if(vec[mid]<target)low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    int n;
    cout<<"Enter size of array";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;

    cout<<"Target"<<endl;
    int index=binsearch(arr, target);
    cout<<"Element at index"<<index<<endl;

}