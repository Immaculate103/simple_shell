#include "main.h"
/**
 * cmd_parser - Parses the input string from the user into arguments
 * @input_string: the string input from the user
 * @argv: an array of strings to store the arguments
 * @wait: a pointer to an integer that determines whether the command should be executed in the background or not
 *
 * Return: none
 */
void cmd_parser(char *input_string, char **argv, int *wait)
{
    int b = 0;

    while (b < SIZE_OF_BUFFER)
    {
        argv[b] = NULL;
        b++;
    }

    *wait = (input_string[strlen(input_string) - 1] == '&') ? 0 : 1;
    input_string[strlen(input_string) - 1] = (*wait == 0) ? '\0' : input_string[strlen(input_string) - 1];
    b = 0;
    argv[b] = strtok(input_string, " ");

    if (argv[b] == NULL)
    {
        return;
    }

    while (argv[b] != NULL)
    {
        b++;
        argv[b] = strtok(NULL, " ");
    }

    argv[b] = NULL;
}
