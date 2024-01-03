#include "monty.h"

/**
 * pint - Prints the value at the top of the stack, followed by a new line.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the script file.
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the script file.
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		*stack = temp->next;
		(*stack)->prev = NULL;
		free(temp);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
