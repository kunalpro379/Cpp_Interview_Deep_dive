#include<iostream>
#include<vector>

using namespace std;
int partition(vector<int>&A, int low, int high){
    int pivot=A[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(A[j]<pivot){
            i=i+1;
            swap(A[i],A[j]);
        }
    }
        swap(A[i+1], A[high]);
        return i+1;

} 
void QuickSort(vector<int>&A, int low, int high){
    if(low<high){
        int pi=partition(A, low, high);
        QuickSort(A, low, pi-1);
        QuickSort(A, pi+1,high);
    }
}
int main(){
    vector<int>A={10,7,9,8,1,5};
    QuickSort(A,0, A.size()-1);
    cout<<"Sorted Array"<<endl;
    for(int x:A)cout<<x<< " "<<endl;
    return 0;

}