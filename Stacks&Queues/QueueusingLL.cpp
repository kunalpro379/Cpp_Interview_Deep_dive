#include<stdio.h>
#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
struct Node* front=NULL;
struct Node* rear=NULL;
void enqueu(int x){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;
    if(rear==NULL){
        front=rear=newNode;
        return;
    }
    rear->next=newNode;
    rear=newNode;
}
void deque(){
    if(front==NULL)return;
    struct Node* temp=front;
    front=front->next;//null
    if(front=NULL)rear=NULL;
    free(temp);
}
void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){

    enqueu(10);
    enqueu(20);
    enqueu(30);

    display();
    deque();
    display();

    return 0;

}

