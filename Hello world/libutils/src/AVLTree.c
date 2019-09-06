#include <stdio.h>
#include <stdlib.h>

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

void tree_print(struct Tree* root,size_t depth){
    for (size_t i = 0; i <depth ; ++i) {
        putchar(' ');
    }
    if(root)
        printf("%d\n",root->data);
    else{
        puts("NULL");
        return;
    }
    tree_print(root->left,depth+1);
    tree_print(root->right,depth+1);
}

struct Tree* createNode(int data, struct Tree* left, struct Tree* right){
    struct Tree* node=malloc(sizeof(struct Tree*));
    node->data=data;
    node->left=left;
    node->right=right;
    return node;
}
