#ifndef SLL_H
#define SLL_H

typedef struct sll sll;

/**
 * @brief Creates an empty linked list
 *
 * This function allocates memory for a new sll instance
 * and initializes its members. 
 *
 * @return A pointer to the newly created list, or NULL
 */
sll *sll_init();

/**
 * @brief Deallocates a linked list
 *
 * This function deallocates memory of an sll instance.
 * To be used when the linked list is no longer needed. 
 *
 * @return void
 */
void sll_free(sll *list);

/**
 * @brief Adds an element at the end of the list
 *
 * This function adds an element at the end of the list
 * in constant time. (addLast)
 * @return 0 on success, -1 on failure
 */
int sll_addl(sll *list, int value);

#endif 
