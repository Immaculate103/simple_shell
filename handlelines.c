#include "main.h"
/**
 * error_h - prints an error message with the prompt
 * @msg: the error message to print
 *
 * Return: none
 */
void error_h(char *msg)
{
    k_puts(prompt_entry());
    k_puts(msg);
}

/**
 * remove_null_term_char - removes the newline character from a string
 * @line: the string to remove the newline character from
 *
 * Return: the modified string
 */
void remove_null_term_char(char *prog_input)
{
    int b = 0;

    while (prog_input[b] != '\n')
    {
        b++;
    }

    prog_input[b] = '\0';
}

/**
 * l_reader - reads a line from stdin
 * @line: a buffer to store the line read from stdin
 *
 * Return: none
 */
void l_reader(char *prog_in)
{
    char *line = NULL;
    size_t len = 0;

    ssize_t read = getline(&line, &len, stdin);

    remove_null_term_char(line);

    if (strcmp(line, "exit") == 0 || read == -1 || strcmp(line, "quit") == 0)
    {
        free(line);
        exit(EXIT_SUCCESS);
    }

    strncpy(prog_in, line, LINE_BUFFER);
    free(line);
}
