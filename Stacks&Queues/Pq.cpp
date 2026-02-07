#include <stdio.h>
#include <stdlib.h>
#include <iostream>
struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* head = NULL;

void insert(int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (head == NULL || priority < head->priority) {
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL && temp->next->priority <= priority) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void delete() {
    if (head == NULL) {
        printf("Priority Queue is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Deleted: %d\n", temp->data);
    head = head->next;
    free(temp);
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("(%d, p=%d) -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);
    insert(40, 0);

    display();
    delete();
    display();

    return 0;
}