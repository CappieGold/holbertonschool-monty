#include "monty.h"

/**
 * push - Pushes an integer onto the top of the stack.
 * This function adds a new element with the specified integer value to the
 * top of the stack. If the argument provided is not an integer or is absent,
 * the function prints an error message and exits.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the script file.
 * @arg: The argument string that should be converted to an integer.
 * Return: Void. The function can exit the program on failure.
 *
 * Note: The function uses atoi to convert the argument to an integer. It
 *       performs error checking to ensure the argument is a valid integer.
 */

void push(stack_t **stack, int line_number, char *arg)
{
	int i = 0;

	if (arg == NULL)
	{
		printf("L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]) && !(i == 0 && arg[i] == '-'))
		{
			printf("L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	int n = atoi(arg);

	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top.
 * This function iterates through the stack and prints each integer value
 * stored in each node. The printing starts from the top of the stack and
 * proceeds downwards.
 *
 * @stack: Pointer to the top of the stack.
 * Return: Void. The function prints to standard output.
 *
 * Note: If the stack is empty, the function doesn't print anything. It uses
 *       a simple while loop to traverse the stack.
 */

void pall(stack_t *stack)
{
	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		stack = stack->next;
	}
}
