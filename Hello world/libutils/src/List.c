#include <stdlib.h>

struct List{
    int data;
    struct List* prev;
    struct List* next;
};

struct List* add(struct List** head,int data){
    if(*head==NULL){
        *head=malloc(sizeof(struct List));
        (*head)->data=data;
        (*head)->prev=NULL;
        (*head)->next=NULL;
        return *head;
    } else{
        struct List* h=*head;
        while(h->next)
            h=h->next;
        h->next=malloc(sizeof(struct List));
        h->next->data=data;
        h->next->prev=h;
        h->next->next=NULL;
        return h->next;
    }
}

void list_remove(struct List** head,struct List* node);

size_t list_count(struct List* head);

struct List* list_find(struct List* head,int data);
