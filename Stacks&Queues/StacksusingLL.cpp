#include<iostream>
#include<stdio.h>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* top=NULL;

void push(int x){
    struct Node* newNode=(struct Node* )malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}
void poop(){
    if(top==NULL)return;
    struct Node* temp=top;
    top=top->next;
    free(temp);
}
void display(){
    struct Node* temp=top;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main(){
    push(10);
    push(20);
    push(30);

    display();
    poop();
    display();

    return 0;
}