#include "monty.h"

/**
 * execute_line - Parses and executes a line of Monty bytecode.
 * This function interprets a single line of Monty bytecode script. It extracts
 * the opcode and any argument from the line,
 * then calls the appropriate function
 * to perform the operation specified by the opcode.
 *
 * @line: String containing the line to be executed.
 * @stack: Double pointer to the top of the stack.
 * @line_number: The line number of the current line in the script file.
 * Return: Void. The function can exit the program on failure.
 *
 * Note: This function is responsible for command parsing and error checking.
 *       It maps opcodes to their corresponding functions.
 */

void execute_line(char *line, stack_t **stack, unsigned int line_number)
{
	char *opcode;
	char *arg;

	opcode = strtok(line, " \t\n");
	arg = strtok(NULL, " \n");

	if (opcode == NULL)
		return;

	if (strcmp(opcode, "push") == 0)
		push(stack, line_number, arg);
	else if (strcmp(opcode, "pall") == 0)
	{
		pall(*stack);
	}
	else if (strcmp(opcode, "pint") == 0)
	{
		pint(stack, line_number);
	}
	else if (strcmp(opcode, "pop") == 0)
	{
		pop(stack, line_number);
	}
	else if (strcmp(opcode, "swap") == 0)
	{
		swap(stack, line_number);
	}
	else if (strcmp(opcode, "add") == 0)
	{
		add(stack, line_number);
	}
	else if (strcmp(opcode, "nop") == 0)
	{
		nop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
