#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>&a, int low, int mid, int high){
    vector<int>temp;
    int left=low;
    int right =mid+1;
    while(left<=mid&&right<=high){
        if(a[left]<a[right]){
            temp.push_back(a[left]);
            left++;
        }else{
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(a[left]);
        left++;
    }while(a[right]<=high){
        temp.push_back(a[right]);
        right++;
    }
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<temp.size();i++){
        a[low+i]=temp[i];
    }

}
void MergeSort(vector<int>&a, int low, int high){
    if(low>=high)return;
    int mid=low+(high-low)/2;
    MergeSort(a,low, mid);
    MergeSort(a, mid+1, high);
    merge(a, low, mid, high);
}
int main(){
    vector<int> a = {5, 2, 4, 6, 1, 3};
    MergeSort(a, 0, a.size() - 1);
    for (int x : a) cout << x << " ";
    return 0;
}