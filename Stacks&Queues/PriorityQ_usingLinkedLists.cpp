#include<stdio.h>
#include<iostream>
#include <stdlib.h>
using namespace std;
struct Node{
    int data;
    int priority;
    struct Node* next;
};
struct Node* createNode(int data, int priority){
    struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    if(node==NULL)printf("Memory Allocation failed");
    node->data=data;
    node->priority=priority;
    node->next=NULL;
    return node;
}
void push(struct Node** head, int data, int priority ){
    struct Node* newNode=createNode(data, priority);
    if(*head==NULL||(*head)->priority>priority){
        newNode->next=*head;
        *head=newNode;
        return;
    }
    struct Node* temp=*head;
    while(temp->next!=NULL&& temp->next->priority<priority){
        temp=temp->next;
    }
    newNode->next=temp->next;temp->next=newNode;
}
void poop(struct Node** head){
    if(*head==NULL)return;
    struct Node* temp=*head;
    *head=(*head)->next;
    free(temp);
}
void peek(struct Node* head){
    if(head==NULL)return;
    cout<<":::"<<head->data<<" "<<head->priority;
}
void display(struct Node* head){
    while(head!=NULL){
        cout<<head->data<<" "<<head->priority;
        head=head->next;
    }
}


int main(){
    struct Node* pq=NULL;
    // so pq node ka pointer =Node* pq
    // Node* pq ka address is & pq
    // so Node** represent the &pq

    push(&pq,10,4);
    push(&pq,11,32);
    push(&pq,41,5);
    push(&pq,15,1);
    push(&pq,95,5);
    push(&pq,23,10);
    push(&pq,85,8);
    push(&pq,53,9);
    push(&pq,153,3);
    push(&pq,42,4);
    push(&pq,21,4);
    push(&pq,9,9);
    display(pq);
    peek(pq);
    poop(&pq);
    display(pq);
}