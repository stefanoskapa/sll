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

void fail();
void test1();
void test2();
void test3();
void test4();
void test5();

int testcase = 0;

int main(void) {
    test1();
    test2();
    test3();
    test4();
    test5();
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
    sll *list = sll_init();
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
target: sll_addl

Add an element at the end of the list
and check if the size increased and
head and tail have been updated.
*/
void test2() {
    testcase++;
    sll *list = sll_init();
    sll_addl(list, 1);
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
target: sll_addl

Add three elements at the end of the list
and check if the size increased and
head and tail have been updated and nodes
are correct.
*/
void test3() {
    testcase++;
    sll *list = sll_init();
    sll_addl(list, 1);
    sll_addl(list, 2);
    sll_addl(list, 3);
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
target: sll_addf

Add an element at the start of the list
and check if the size increased and
head and tail have been updated.
*/
void test4() {
    testcase++;
    sll *list = sll_init();
    sll_addf(list, 1);
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
target: sll_addf

Add three elements at the start of the list
and check if the size increased and
head and tail have been updated and nodes
are correct.
*/
void test5() {
    testcase++;
    sll *list = sll_init();
    sll_addf(list, 1);
    sll_addf(list, 2);
    sll_addf(list, 3);
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




void fail() {
    printf("Test %d failed!\n", testcase);
    exit(1);
}
