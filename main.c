#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter.
 * This function is the starting point of the program. It handles the initial
 * processing of command-line arguments, opens the Monty bytecode file, and
 * reads it line by line. Each line of the file is processed as a command by
 * calling the execute_line function. After processing all lines, it cleans up
 * by closing the file and freeing any allocated memory.
 *
 * @argc: The count of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: EXIT_SUCCESS on successful execution, or EXIT_FAILURE on errors.
 *
 * Note: The function ensures proper command-line argument usage and handles
 *       file opening and reading errors. It relies on other functions like
 *       execute_line and free_stack for bytecode processing
 *       and memory management.
 *       The function assumes that the Monty bytecode file
 *       is correctly formatted.
 */

int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		line_number++;
		execute_line(line, &stack, line_number);
	}

	free(line);
	fclose(fp);
	free_stack(stack);
	return (0);
}
