#include "list.h"

#include <stdio.h>
#include <stdlib.h>

struct node* init(const struct door* door) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node->data = *door;
        new_node->next = NULL;
    }
    return new_node;
}

struct node* add_door(struct node* elem, const struct door* door) {
    if (elem == NULL) return NULL;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node != NULL) {
        new_node->data = *door;
        new_node->next = elem->next;
        elem->next = new_node;
    }
    return new_node;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        if (current->data.id == door_id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem == NULL || root == NULL) return root;

    if (elem == root) {
        struct node* temp = root;
        root = root->next;
        free(temp);
    } else {
        struct node* current = root;
        while (current->next != NULL && current->next != elem) {
            current = current->next;
        }
        if (current->next == elem) {
            current->next = elem->next;
            free(elem);
        }
    }
    return root;
}

void destroy(struct node* root) {
    struct node* current = root;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
}