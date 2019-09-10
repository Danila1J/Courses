#include <libutils/AVLTree.h>
#include <libutils/List.h>

int main() {
//    struct List* head=NULL;
//    list_add(&head,1);
//    list_add(&head,2);
//    list_insert(&head,4);
//    list_add(&head,3);
//    list_add(&head,4);
//    list_add(&head,5);
//    list_print(n2);
//    list_print(head);
//    printf("---------------------\n");
//    list_remove(&head,n2);
//    list_print(head);
    struct Tree *root = NULL;
    root = tree_insert(root, 4);
    root = tree_insert(root, 5);
    root = tree_insert(root, 6);
    root = tree_insert(root, 2);
    root = tree_insert(root, 1);
    root = tree_insert(root, 3);
    tree_print(root, 0);

    tree_free(root);
}
