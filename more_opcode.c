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
