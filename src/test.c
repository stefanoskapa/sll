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

void fail();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();

int testcase = 0;

int main(void) {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    printf("All %d tests passed!\n", testcase);
    return EXIT_SUCCESS;
}



/*
TEST 1
--------
target: sll_init

Create an instance of sll and check
if it has been initialized correctly
*/
void test1() {
    testcase++;
    Sll *list = sll_init();
    if (list->head != NULL ||
        list->tail != NULL ||
        list->size != 0) {
        fail();
    }
    sll_free(list);
}

/*
TEST 2
--------
target: sll_addLast

Add an element at the end of the list
and check if the size increased and
head and tail have been updated.
*/
void test2() {
    testcase++;
    Sll *list = sll_init();
    sll_addLast(list, 1);
    if (list->head == NULL ||
        list->tail == NULL ||
        list->size != 1) {
        fail();
    }
    sll_free(list);
}

/*
TEST 3
--------
target: sll_addLast

Add three elements at the end of the list
and check if the size increased and
head and tail have been updated and nodes
are correct.
*/
void test3() {
    testcase++;
    Sll *list = sll_init();
    sll_addLast(list, 1);
    sll_addLast(list, 2);
    sll_addLast(list, 3);
    if (list->head == NULL ||
        list->tail == NULL ||
        list->size != 3    ||
        list->head->value != 1 ||
        list->head->next->value != 2 ||
        list->head->next->next->value != 3
        ) {
        fail();
    }
    sll_free(list);
}

/*
TEST 4
--------
target: sll_addFirst

Add an element at the start of the list
and check if the size increased and
head and tail have been updated.
*/
void test4() {
    testcase++;
    Sll *list = sll_init();
    sll_addFirst(list, 1);
    if (list->head == NULL ||
        list->tail == NULL ||
        list->size != 1) {
        fail();
    }
    sll_free(list);
}

/*
TEST 5
--------
target: sll_addFirst

Add three elements at the start of the list
and check if the size increased and
head and tail have been updated and nodes
are correct.
*/
void test5() {
    testcase++;
    Sll *list = sll_init();
    sll_addFirst(list, 1);
    sll_addFirst(list, 2);
    sll_addFirst(list, 3);
    if (list->head == NULL ||
        list->tail == NULL ||
        list->size != 3    ||
        list->head->value != 3 ||
        list->head->next->value != 2 ||
        list->head->next->next->value != 1
        ) {
        fail();
    }
    sll_free(list);
}


/*
TEST 6
--------
target: sll_getAt

Add three elements at the start of the list
and check if they can be accessed by index.
*/
void test6() {
    testcase++;
    Sll *list = sll_init();
    sll_addFirst(list, 1);
    sll_addFirst(list, 2);
    sll_addFirst(list, 3);

    if (sll_getAt(list, 0) == NULL || *(sll_getAt(list, 0)) != 3) {
        fail();
    } 
    
    if (sll_getAt(list, 1) == NULL || *(sll_getAt(list, 1)) != 2) {
        fail();
    } 

    if (sll_getAt(list, 2) == NULL || *(sll_getAt(list, 2)) != 1) {
        fail();
    } 

    sll_free(list);
}





void fail() {
    printf("Test %d failed!\n", testcase);
    exit(1);
}
