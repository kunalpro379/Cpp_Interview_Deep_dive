//find the miniimum elements and place it at the correct position
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
void CountingSort(vector<int>&a){
    int n=a.size();
    int maxVal= *max_element(a.begin(), a.end());
    vector<int>count(maxVal+1,0);
    for(int x:a)count[x]++;

    int idx=0;
    for(int i=0;i<=maxVal;i++){
        while(--count[i]>=0){
            a[idx++]=i;
        }
    }
}
int main(){
    vector<int>a={
        12, 11, 13, 5, 6,4,3,3,3,3,3,2,1
    };
    CountingSort(a);
    for(auto  const& it: a){
        cout<<it<<endl;
    }
}

