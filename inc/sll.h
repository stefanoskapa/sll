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

#endif 
