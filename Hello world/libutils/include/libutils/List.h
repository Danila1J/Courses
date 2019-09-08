#include <stdlib.h>

struct List;

struct List* list_add(struct List** head,int data);

void list_remove(struct List** head,struct List* node);

size_t list_count(struct List* head);

struct List* list_find(struct List* head,int data);

void list_print(struct List* head);
