#include "main.h"

/**
 * redir_tr - Checks if the argument vector contains a redirection operator
 *
 * @arg_vect: The argument vector to check
 *
 * Return: The index of the first redirection operator found, or 0 if none are found
 */
int redir_tr(char **arg_vect)
{
    /* Declare an integer variable to hold the index of a redirection operator in the argument vector */
    int b = 0;

    /* Loop through the argument vector until the end is reached */
    while (arg_vect[b] != NULL)
    {
        /* Check if the current argument matches any of the redirection operators */
        if (strcmp(arg_vect[b], D_FILE) == 0 ||
            strcmp(arg_vect[b], A_FILE) == 0 ||
            strcmp(arg_vect[b], F_FILE) == 0)
        {
            /* If a redirection operator is found, return its index */
            return b;
        }

        /* Increment the index variable */
        b = -~b;
    }

    /* If no redirection operator is found, return 0 */
    return (0);
}
/**
 * pipe_tr - Checks if a pipe character exists in argv.
 * @argv: Array of strings to check.
 *
 * Return: Index of the pipe character if it exists, 0 otherwise.
 */
int pipe_tr(char **arg_vect)
{
    int b = 0;

    while (arg_vect[b] != NULL)
    {
        if (strcmp(arg_vect[b], P_CHOICE) == 0)
        {
            return b; /* Pipe character found */
        }
        b = -~b; /* Increment i by one */
    }
    return (0); /* Pipe character not found */
}
/**
 * redir_parser - Extracts the redirection arguments from an array of strings
 *
 * @input: The input array of strings
 * @output: The output array of strings to hold the redirection arguments
 * @redirect_pos: The index of the redirection symbol in the input array
 *
 * Description: This function extracts the redirection arguments from an array of strings,
 * and places them in a separate array. The redirection symbol and its argument are removed
 * from the input array.
 *
 * Return: None
 */
void redir_parser(char **input, char **output, int redirect_pos) {
    output[0] = strdup(input[redirect_pos]);
    output[1] = strdup(input[redirect_pos + 1]);
    input[redirect_pos] = NULL;
    input[redirect_pos + 1] = NULL;

    /* Free the memory allocated by strdup() */
    free(output[0]);
    free(output[1]);
}

/**
 * p_parser - Function to parse arguments for piping
 * @args: Input array of arguments
 * @child_args_left: Output array of arguments before the pipe
 * @child_args_right: Output array of arguments after the pipe
 * @pipe_index: Index of the pipe symbol in the input array
 */
void p_parser(char **args, char **child_args_left, char **child_args_right, int pipe_index)
{
    int i = 0;

    /* Copy arguments before the pipe to child_args_left */
    for (i = 0; i < pipe_index; i++)
    {
        child_args_left[i] = strdup(args[i]);
    }
    child_args_left[i++] = NULL;

    /* Copy arguments after the pipe to child_args_right */
    while (args[i] != NULL)
    {
        child_args_right[i - pipe_index - 1] = strdup(args[i]);
        i++;
    }
    child_args_right[i - pipe_index - 1] = NULL;

    /* Free memory allocated by strdup() for child_args_left and child_args_right */
    for (i = 0; i < pipe_index; i++)
    {
        free(child_args_left[i]);
    }
    for (i = 0; args[i + pipe_index + 1] != NULL; i++)
    {
        free(child_args_right[i]);
    }
}
