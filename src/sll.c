#include <stdio.h>
#include <stdlib.h>
#include "../inc/sll.h"

typedef struct sll_node {
    int value;
    struct sll_node *next;
} sll_node;

struct sll {
    sll_node *head;
    sll_node *tail;
    int size;
};



sll *sll_init() {
    sll *list = (sll*) malloc(sizeof(sll));
    if (list == NULL) {
        return NULL;
    }
    *list = (sll){NULL, NULL, 0};    
    return list;
}

int sll_addl(sll *list, int value) {

    sll_node *node = (sll_node*) malloc(sizeof(sll_node));
    if (node == NULL) {
        return -1;
    }
    *node = (sll_node){value, NULL};
    
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


void sll_free(sll *list) {
    sll_node *node = list->head;
    sll_node *next;
    while(node != NULL) {
        next = node->next;
        free(node);
        node = next; 
    }
    free(list);
}
