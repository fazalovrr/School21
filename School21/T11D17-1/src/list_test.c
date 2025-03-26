#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "door_struct.h"

int test_add_door();
int test_remove_door();

int main() {
    printf("Тест на добавление двери. Результат: ");
    if (test_add_door() == 0) {
        printf("FAIL\n");
    } else {
        printf("SUCCESS\n");
    }
    printf("Тест на удаление двери. Результат: ");
    if (test_remove_door() == 0) {
        printf("FAIL\n");
    } else {
        printf("SUCCESS\n");
    }

    return 0;
}

int test_add_door() {
    int result = 1;

    struct door door1 = {1, 0};
    struct door door2 = {2, 1};

    struct node* root = init(&door1);
    if (root == NULL) return 0;

    struct node* added_node = add_door(root, &door2);
    if (added_node == NULL || added_node->data.id != door2.id) {
        destroy(root);
        return 0;
    }

    if (root->next != added_node) {
        destroy(root);
        return 0;
    }

    destroy(root);
    return result;
}

int test_remove_door() {
    int result = 1;

    struct door door1 = {1, 0};
    struct door door2 = {2, 1};

    struct node* root = init(&door1);
    if (root == NULL) return 0;

    add_door(root, &door2);

    struct node* node_to_remove = find_door(2, root);
    if (node_to_remove == NULL) {
        destroy(root);
        return 0;
    }

    root = remove_door(node_to_remove, root);

    if (find_door(2, root) != NULL) {
        destroy(root);
        return 0;
    }

    destroy(root);
    return result;
}