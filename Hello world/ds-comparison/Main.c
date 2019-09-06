#include <libutils/AVLTree.h>

int main(){
    struct Tree* n1= createNode(1,NULL,NULL);
    struct Tree* n3= createNode(3,NULL,NULL);
    struct Tree* n2= createNode(2,n1,n3);
    struct Tree* n6= createNode(6,NULL,NULL);
    struct Tree* n5= createNode(5,NULL,n6);
    struct Tree* n4= createNode(4,n2,n5);
    tree_print(n4,0);
}
