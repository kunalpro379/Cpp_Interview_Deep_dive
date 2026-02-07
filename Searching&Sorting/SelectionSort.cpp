//find the miniimum elements and place it at the correct position
#include<iostream>
#include<vector>
using namespace std;
void selectionSort(vector<int>&a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int minIdx=i;
        for(int j=i+1;j<n;j++){//mistake: j<n-1
            if(a[j]<a[minIdx]){
                minIdx=j;
            }
        }
        swap(a[i], a[minIdx]);
    }
}
int main(){
    vector<int>a={
        12,1,21,42,435,54,564,3,2
    };
    selectionSort(a);
    for(auto  const& it: a){
        cout<<it<<endl;
    }
}

