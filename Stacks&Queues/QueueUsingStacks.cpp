#include <stack>
#include<iostream>
using namespace std;
class QueueUsingStacks{
    private:
    stack<int>s1, s2;
    public:
    void enqueheavy(int x){
        //move all element from s1 to s2
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        //push new element to s1
        s1.push(x);
        //move everything back from s2 to s1
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }

    }
    int deque(){
        if(s1.empty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x=s1.top();
        s1.pop();
        return x;
    }
    int dequeheavy(){
        if(s1.empty()&&s2.empty())return -1;
        if(s2.empty())while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        s2.pop();
        return x;
    }
    int enque(){
        if(s1.empty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int x=s1.top();
        s1.pop();
        return x;
    }
    int frontheavy(){
        if(s1.empty()&&s2.empty())return -1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }return s2.top();
    }
    int front(){
        if(s1.empty())return -1;
        return s1.top();
    }
    bool empty() {
        return s1.empty();
    }
    
    int size() {
        return s1.size();
    }
};
class Optmized{
    
};
int main(){

}