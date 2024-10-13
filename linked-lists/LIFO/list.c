#include <stdilb.h>
#include "list.h"


node* push(node* head, int value) {
    node* new_node = malloc(sizeof(node));

    if (new_node == NULL)
        return head;

    new_node->n = value;
    new_node->next = head;
    head = new_node;
    
    return head;
}


node* pop(node* head, int value) {
    if (head == NULL)
        return head;
    
    if (head->n == value) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    node* current = head->next;
    node* previous = head;
    
    while(current != NULL) {
        if (current->n == value) {
            previous->next = current->next;
            free(current);
            return head;
        }
        previous = current;
        current = current->next;
    }
    
    return head;
}


// peek function (top)
