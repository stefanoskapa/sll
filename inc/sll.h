#ifndef SLL_H
#define SLL_H

#include <stdlib.h>

typedef struct Sll Sll;

/**
 * @brief Creates an empty linked list
 *
 * This function allocates memory for a new sll instance
 * and initializes its members. 
 *
 * @return A pointer to the newly created list, or NULL
 */
Sll *sll_init();

/**
 * @brief Deallocates a linked list
 *
 * This function deallocates memory of an sll instance.
 * To be used when the linked list is no longer needed. 
 *
 * @return void
 */
void sll_free(Sll *list);

/**
 * @brief Adds an element at the end of the list
 *
 * This function adds an element at the end of the list
 * in constant time.
 * @return 0 on success, -1 on failure
 */
int sll_addLast(Sll *list, int value);

/**
 * @brief Adds an element at the start of the list
 *
 * This function adds an element at the start of the list
 * in constant time.
 * @return 0 on success, -1 on failure
 */
int sll_addFirst(Sll *list, int value);


/**
 * @brief Retrieves the element and a given index
 *
 * This function returns the value of an element 
 * at the specified index.
 * 
 * @return NULL on error, otherwise the element value
 */
int *sll_getAt(Sll *list, size_t index);


/**
 * @brief Returns the list size
 *
 * @return list size
 */
int sll_size(Sll *list);

#endif 
