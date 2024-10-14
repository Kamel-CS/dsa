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


node* add_at_index(node* head; int index, int value) {
    node* new_node = malloc(sizeof(node));
    new_node->n = value;

    node* current = head;
    for (int i = 1; i < index - 1; i++) {
        if (current == NULL)
            return head;
        current = current->next;
    }

    new_node = current->next;
    current->next = new_node;

    return head;
}


node *pop(node* head) {
    if (head == NULL)
        return head;

    node* temp = head;
    head = head->next;
    free(temp);

    return head;
}


node* delete_node(node* head, int value) {
    if (head == NULL)
        return head;
    
    if (head->n == value)
        return pop(head);
    
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


int list_size(node* head) {
    int count = 0;
    node* current = head;
    
    while(current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}


void free_list(node *head) {
    node* current = head;

    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
}
