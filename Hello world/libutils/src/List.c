#include <stdlib.h>
#include <stdio.h>

struct List {
    int data;
    struct List *prev;
    struct List *next;
};

struct List *list_add(struct List **head, int data) {
    if (*head == NULL) {
        *head = malloc(sizeof(struct List));
        (*head)->data = data;
        (*head)->prev = NULL;
        (*head)->next = NULL;
        return *head;
    } else {
        struct List *h = *head;
        while (h->next)
            h = h->next;
        h->next = malloc(sizeof(struct List));
        h->next->data = data;
        h->next->prev = h;
        h->next->next = NULL;
        return h->next;
    }
}

struct List *list_search(struct List *head, int data) {
    while (head) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void list_remove(struct List **head, struct List *node) {
    if (list_search(*head, node->data) != NULL) {
        if (node->prev == NULL && node->next == NULL) {
            (*head)->next = NULL;
            *head = NULL;
            free(*head);
            return;
        } else if (node->prev == NULL) {
            struct List *temp = *head;
            temp = temp->next;
            temp->prev = NULL;
            *head = temp;
            free(node);
            return;
        }
        if (node->next == NULL && node->prev != NULL) {
            struct List *temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp = temp->prev;
            temp->next = NULL;
            free(node);
            return;
        }
        struct List *temp = *head;
        while (temp != node) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(node);

    }
}

size_t list_count(struct List *head) {
    size_t count = 0;
    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}

void list_print(struct List *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void list_free(struct List *head) {
    struct List *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int list_get(struct List *node) {
    return node->data;
}

void list_set(struct List *node, int newData) {
    node->data = newData;
}

struct List *list_insert(struct List **node, int newData) {
    if (*node == NULL) {
        return list_add(node, newData);
    } else if ((*node)->prev == NULL) {
        struct List *temp = list_add(node, newData);
        (*node)->next = temp->next;
        temp->next = *node;
        temp->prev = NULL;
        (*node)->prev = temp;
        *node=temp;
        return temp;
    }

    struct List *tempH = *node;
    while (tempH != *node) {
        tempH = tempH->next;
    }
    struct List *temp = list_add(node, newData);
    (*node)->next = temp->next;
    temp->next = *node;
    temp->prev = (*node)->prev;
    (*node)->prev = temp;
    temp->prev->next = temp;
    return temp;

}
