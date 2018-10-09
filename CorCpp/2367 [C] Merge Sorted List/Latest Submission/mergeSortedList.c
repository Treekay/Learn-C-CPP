#include "mergeSortedList.h"

void push_front(node** head, int val){
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));
        (*head)->val = val;
        (*head)->next = NULL;
    }
    else {
        node* poi = (node*)malloc(sizeof(node));
        poi->val = val;
        poi->next = *head;
        *head = poi;
    }
}

node* mergeSortedList(node* head1, node* head2){
    node* current1 = head1;
    node* current2 = head2;
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    while (current2 != NULL){
        current1 = head1;
        if(current2->val < head1->val){
            node* poi = current2->next;
            current2->next = head1;
            head1 = current2;
            current2 = poi;
        }
        else {
            while (current1->next != NULL){
                if (current2->val < current1->next->val) {
                    node* poi = current2->next;
                    current2->next = current1->next;
                    current1->next = current2;
                    current2 = poi;
                    break;
                }
                current1 = current1->next;
            }
            if (current1->next == NULL) {
                node* poi = current2->next;
                current2->next = NULL;
                current1->next = current2;
                current2 = poi;
                
            }
        }
    }
    return head1;
}