 #include <stdio.h>
#include <malloc.h>
#include "Node.h"

void push(Node** top, int n){
    Node* temp;
    temp = (Node*)malloc(sizeof(Node));

    if (!temp) return;

    temp->num = n;
    temp->next = *top;

    *top = temp;
}

int pop(Node** top){
    int data;
    Node* temp;
    if (*top == NULL) return -1;

    temp = *top;
    *top = temp->next;
    data = temp->num;
    free(temp);
    return data;
}

void del(Node** top){
    Node* temp;
    Node* poi;
    poi = *top;
    while (poi->next){
        temp = poi->next;
        poi->next = temp->next;
        free(temp);
    }
    free(poi);
}