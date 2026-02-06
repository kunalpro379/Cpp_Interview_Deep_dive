#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    Node* next;
};
struct Node* head=NULL;
struct Node* createNode(int data){
    struct Node* n=(struct Node*)malloc(sizeof(struct Node*));
    n->next=NULL;
    n->data=data;
}
void InsertAtBeginning(int data){
    struct Node* n=createNode(data);
    n->next=head;
    head=n;
}

void InsertAtEnd(int data){
    struct Node* n=createNode(data);
    if(!head)head=n;
    struct Node* temp=head;
    while (temp->next)
        temp = temp->next;
    temp->next = n;
}

void InsertAtPos(int data, int pos){
    if(pos==1){
        InsertAtBeginning();
        return;
    }
    struct Node* temp=head;
    for(int i=0;i=pos-1;i++){
        if(temp)temp=temp->next;
    }
    struct Node* n=createNode(data);
    n->next=temp->next;
    temp->next=n;
}

void deleteBegin(){
    if(!head)return;
    struct Node* temp=head;
    head=head->next;
    free(temp);
}

void deleteEnd(){}

void deleteAtPos(){}

int search(){}

void display(){}
void free(){}

int main(){

}