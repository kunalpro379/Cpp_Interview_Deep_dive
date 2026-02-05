#include<iostream>
#include<vector>
using namespace std;
void bubbleSort(vector<int>&a){
    int n= a.size();
    bool flag=false;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j], a[j+1]);
                flag=true;
            }
        }
        if(!flag)break;

    }
}
int main(){
    vector<int>a={
        12,1,21,42,435,54,564,3,2
    };
    bubbleSort(a);
    for(auto  const& it: a){
        cout<<it<<endl;
    }

    return 0;
}