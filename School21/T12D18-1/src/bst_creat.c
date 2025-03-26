#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
    t_btree *node1 = bstree_create_node(1);
    if (node1) {
        printf("Узел 1 создан: item: %d, left: %p, right: %p\n", node1->item, (void *)node1->left,
               (void *)node1->right);
    } else {
        printf("Ошибка при создании узла\n");
    }

    t_btree *node2 = bstree_create_node(2);
    if (node2) {
        printf("Узел 2 создан: item = %d, left = %p, right = %p\n", node2->item, (void *)node2->left,
               (void *)node2->right);
    } else {
        printf("Ошибка создания узла\n");
    }

    free(node1);
    free(node2);

    return 0;
}