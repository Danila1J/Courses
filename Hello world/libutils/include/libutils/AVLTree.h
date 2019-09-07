#include <stdio.h>

struct Tree;

void tree_print(struct Tree *root, size_t depth);
struct Tree *tree_insert(struct Tree *p, int k);
struct Tree* tree_remove(struct Tree* p, int k);
void tree_free(struct Tree *node);
