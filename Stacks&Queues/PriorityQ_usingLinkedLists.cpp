#include<stdio.h>
#include <stdlib.h>
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

int main(){
    struct Node* pq=NULL;

}