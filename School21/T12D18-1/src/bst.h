#ifndef BST_H
#define BST_H

typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    int item;
} t_btree;

t_btree *bstree_create_node(int item);
void bstree_insert(t_btree *root, int item, int (*cmpf) (int, int));

#endif