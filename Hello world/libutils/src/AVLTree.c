#include <stdio.h>
#include <stdlib.h>

struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
    unsigned char height;
};

void tree_print(struct Tree *root, size_t depth) {
    for (size_t i = 0; i < depth; ++i) {
        putchar(' ');
    }
    if (root)
        printf("%d\n", root->data);
    else {
        puts("NULL");
        return;
    }
    tree_print(root->left, depth + 1);
    tree_print(root->right, depth + 1);
}

struct Tree *createNode(int data, struct Tree *left, struct Tree *right) {
    struct Tree *node = malloc(sizeof(struct Tree *));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

unsigned char height(struct Tree *p) {
    return p ? p->height : 0;
}

int bfactor(struct Tree *p) {
    return height(p->right) - height(p->left);
}

void fixheight(struct Tree *p) {
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl > hr ? hl : hr) + 1;
}

struct Tree *rotateright(struct Tree *p) // правый поворот вокруг p
{
    struct Tree *q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

struct Tree *rotateleft(struct Tree *q) // левый поворот вокруг q
{
    struct Tree *p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

struct Tree *balance(struct Tree *p) // балансировка узла p
{
    fixheight(p);
    if (bfactor(p) == 2) {
        if (bfactor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if (bfactor(p) == -2) {
        if (bfactor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // балансировка не нужна
}

struct Tree *tree_insert(struct Tree *p, int k) // вставка ключа k в дерево с корнем p
{
    if (!p) {
        struct Tree *tree = malloc(sizeof(struct Tree));
        tree->data = k;
        return tree;
    }
    if (k < p->data)
        p->left = tree_insert(p->left, k);
    else
        p->right = tree_insert(p->right, k);
    return balance(p);
}

struct Tree *findmin(struct Tree *p) // поиск узла с минимальным ключом в дереве p
{
    return p->left ? findmin(p->left) : p;
}

struct Tree *removemin(struct Tree *p) // удаление узла с минимальным ключом из дерева p
{
    if (p->left == 0)
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

struct Tree *tree_remove(struct Tree *p, int k) // удаление ключа k из дерева p
{
    if (!p) return 0;
    if (k < p->data)
        p->left = tree_remove(p->left, k);
    else if (k > p->data)
        p->right = tree_remove(p->right, k);
    else //  k == p->key
    {
        struct Tree *q = p->left;
        struct Tree *r = p->right;
        free(p);
        if (!r) return q;
        struct Tree *min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

void tree_free(struct Tree *node) {
    if (node != NULL) {
        tree_free(node->right);
        tree_free(node->left);
        free(node);
    }
}
