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

int testcase = 0;

int main(void) {
    test1();
    printf("All %d tests passed!\n", testcase);
    return EXIT_SUCCESS;
}



/*

TEST 1
--------
target: sll_init()

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

}

void fail() {
    printf("Test %d failed!\n", testcase);
    exit(1);
}
