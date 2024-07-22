#include <stdio.h>
#include <stdlib.h>
#include "../inc/sll.h"

typedef struct Sll_node {
    int value;
    struct Sll_node *next;
} Sll_node;

struct Sll {
    Sll_node *head;
    Sll_node *tail;
    size_t size;
};


Sll *sll_init() {
    Sll *list = (Sll*) malloc(sizeof(Sll));
    if (list == NULL) {
        return NULL;
    }
    *list = (Sll){NULL, NULL, 0};    
    return list;
}

int sll_addLast(Sll *list, int value) {

    Sll_node *node = (Sll_node*) malloc(sizeof(Sll_node));
    if (node == NULL) {
        return -1;
    }
    *node = (Sll_node){value, NULL};
    
    if (list->head == NULL) {
        list->head = node;
        list->tail = node; 
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
    return 0;
}

int sll_addFirst(Sll *list, int value) {

    Sll_node *node = (Sll_node*) malloc(sizeof(Sll_node));
    if (node == NULL) {
        return -1;
    }
    *node = (Sll_node){value, list->head};
    
    if (list->head == NULL) {
        list->head = node;
        list->tail = node; 
    } else {
        list->head = node;
    }
    list->size++;
    return 0;
}

int *sll_getAt(Sll *list, size_t index) {

    if (index >= list->size) {
        return NULL;
    } 
    
    Sll_node *node = list->head;
    for (size_t i = 0; i < index; i++) {
        node = node->next;
    }
    
    return &(node->value);
    
}




int sll_size(Sll* list) {
    return list->size;
}

void sll_free(Sll *list) {
    Sll_node *node = list->head;
    Sll_node *next;
    while(node != NULL) {
        next = node->next;
        free(node);
        node = next; 
    }
    free(list);
}
