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

/**
 * swap - Swaps the top two elements of the stack.
 * This function switches the positions of the top two elements of the stack.
 * It is used to manipulate the order of
 * the elements for subsequent operations.
 * If the stack contains less than two elements, the function prints an error
 * message and exits the program.
 *
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the script file. Used for error
 *               messaging.
 * Return: Void. The function terminates the program with EXIT_FAILURE
 *         in case of an error.
 *
 * Note: The function assumes that the stack has been properly initialized and
 *       checks if there are at least two elements
 *       in it before performing the swap.
 *       It modifies the links in the stack nodes to swap their positions.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->prev = tmp;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The current line number in the script file.
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack || !stack || !temp->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(temp->next)->n += temp->n;
	pop(&temp, line_number);

	*stack = temp;
}

/**
 * nop - A no-operation function for the Monty bytecode interpreter.
 * The 'nop' opcode is intended to have no effect when executed. It serves as a
 * placeholder or for instructional purposes in Monty bytecode scripts. This
 * function is called when the 'nop' opcode is encountered but does not perform
 * any operation on the stack.
 *
 * @stack: Double pointer to the top of the stack.
 *         Not used in this function but
 *         included for consistency with other stack operations.
 * @line_number: The current line number in the script file. Not used in this
 *               function but included for potential
 *               future use and error reporting.
 * Return: Void. Since this function does not perform any operation, it has no
 *         return value or side effects.
 *
 * Note: While the function does not perform any action, it is essential for
 *       complying with the Monty bytecode specification and for ensuring that
 *       the interpreter can process scripts containing 'nop' without errors.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
