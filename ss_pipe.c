#include "main.h"
/**
 * pipe_ss - Executes a pipe command.
 * @args: List of arguments to the command.
 *
 * Return: 1 if pipe is performed, 0 otherwise.
 */
int pipe_ss(char **args)
{
    int pipe_index = pipe_tr(args);

    if (pipe_index != 0)
    {
        char *child_args_1[S_PIPE];
        char *child_args_2[S_PIPE];
        p_parser(args, child_args_1, child_args_2, pipe_index);
        ch_p_ex(child_args_1, child_args_2);
        return (1);
    }
    return (0);
}
