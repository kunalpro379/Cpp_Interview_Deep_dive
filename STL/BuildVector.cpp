#include <iostream>
using namespace std;
template <typename T>
class Vector{
    private:
    T* data;
    int sz;
    int cap;
    void grow(){
        int newCap=(cap==0)?1:cap*2;
        T* newData=new T[newCap];
        for(int i=0;i<sz;i++)newData[i]=data[i];
        delete[] data;
        data=newData;
        cap=newCap;
    }
    public:
    Vector(){
        data=nullptr;
        sz=0;
        cap=0;
    }
    ~Vector(){
        delete[] data;
    }
    void push_back(T value){
        if(sz==cap)grow();
        data[sz++]=value;
    }
    void poop_back(){
        if(sz>0)sz--;
    }
    int size(){
        return sz;
    }
    int capacity(){
        return cap;
    }
    void clear(){
        sz=0;
    }
    T& operator[](int index){
        return data[index];
    }
};
int main() {
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    cout << "\nSize: " << v.size();
    cout << "\nCapacity: " << v.capacity();

    v.poop_back();
    cout << "\nAfter pop size: " << v.size();
}