#include <stdio.h>

struct Tree;

void tree_print(struct Tree *root, size_t depth);
struct Tree* createNode(int data, struct Tree* left, struct Tree* right);
