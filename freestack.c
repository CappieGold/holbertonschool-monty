#include "monty.h"

/**
 * free_stack - Frees a stack.
 * This function releases all the memory allocated for the stack. It iterates
 * through the stack and frees each node until the entire stack is cleared.
 *
 * @stack: Pointer to the top of the stack.
 * Return: Void. The function frees allocated memory.
 *
 * Note: It is important to use this function to avoid memory leaks, especially
 *       after the completion of stack operations or before the program exits.
 */

void free_stack(stack_t *stack)
{
	while (stack != NULL)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
}
