#include "bst.h"

#include <stdlib.h>

t_btree *bstree_create_node(int item) {
    t_btree *node = (t_btree *)malloc(sizeof(t_btree));
    if (node) {
        node->item = item;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void bstree_insert(t_btree *root, int item, int (*cmpf) (int, int)){

    
}