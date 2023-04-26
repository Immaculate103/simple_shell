#include "main.h"

/**
 * k_puts - Outputs a string to stdout and appends a newline character
 * @s: The string to output
 * Return: The number of characters printed, including the newline
*/

int k_puts(const char *s)
{
    int len = strlen(s);
    int ret = fwrite(s, sizeof(char), len, stdout);
    if (ret == len)
    {
        ret += fwrite("\n", sizeof(char), 1, stdout);
    }
    else
    {
        return EOF;
    }
    return ret;
}

/**
 * ss_hist - display and execute a command from history
 * @history: a string containing the history of commands
 * @redir_args: an array of strings containing arguments for redirection
 *
 * This function takes a string containing the history of commands, selects
 * the most recent command, and executes it. If no commands are found in the
 * history, an error message is printed to stderr. The redir_args array can be
 * used to specify input/output redirection.
 *
 * Return: 0 on success, 1 on failure
 */
int ss_hist(char *prog_hist, char **args_red)
{
    char *args_pres[SIZE_OF_BUFFER];
    char pres_cmd[LINE_BUFFER];
    int wait_ex;
    int num_results;

    if (prog_hist[0] == '\0')
    {
        fprintf(stderr, "No commands in history\n");
        return 1;
    }

    strcpy(pres_cmd, prog_hist);
    k_puts(pres_cmd);
    cmd_parser(pres_cmd, args_pres, &wait_ex);
    num_results = 0;
    cmd_ex(args_pres, args_red, wait_ex, num_results);
    return num_results;
}
