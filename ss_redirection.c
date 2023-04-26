#include "main.h"
/**
 * ss_redir - Redirects input/output of commands.
 * @command_args: List of arguments to the command.
 * @redirection_args: List of arguments to the redirection operator.
 *
 * Return: 1 if redirection is performed, 0 otherwise.
 */
int ss_redir(char **command_args, char **redirection_args)
{
    int redirection_operator_index = redir_tr(command_args);

    if (redirection_operator_index != 0)
    {
        redir_parser(command_args, redirection_args, redirection_operator_index);
        if (strcmp(redirection_args[0], ">") == 0)
        {
            ch_ovwrt_ex_f(command_args, redirection_args);
        }
        else if (strcmp(redirection_args[0], "<") == 0)
        {
            ch_ovwrt_ex(command_args, redirection_args);
        }
        else if (strcmp(redirection_args[0], ">>") == 0)
        {
            ch_ex_a_f(command_args, redirection_args);
        }
        return (1);
    }
    return (0);
}
