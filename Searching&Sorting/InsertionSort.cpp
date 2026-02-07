//find the miniimum elements and place it at the correct position
#include<iostream>
#include<vector>
using namespace std;
void InsertionSort(vector<int>&a){
    int n=a.size();
    for(int i=0;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0&& a[j]>key){
            a[j+1]=a[j];j--;
        }
        a[j+1]=key;
    }

}
//[12 | 11 13 5 6]
int main(){
    vector<int>a={
        12,1,21,42,435,54,564,3,2
    };
    InsertionSort(a);
    for(auto  const& it: a){
        cout<<it<<endl;
    }
}

