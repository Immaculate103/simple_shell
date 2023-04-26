#include "main.h"
/**
 * set_prev_command - Sets the previous command in the history
 * @history: string representing the command history
 * @line: string representing the current command line
 *
 * Return: void
 */
void set_prev_command(char *prog_hist, char *prog_input)
{
    strcpy(prog_hist, prog_input);
}
/**
 * get_prev_command - Gets the previous command from the history
 * @history: string representing the command history
 *
 * Return: Pointer to the previous command in the history, or NULL if the history is empty
 */
char *get_prev_command(char *prog_hist)
{
    if (prog_hist[0] == '\0')
    {
        fprintf(stderr, "No commands in history\n");
        return NULL;
    }
    return prog_hist;
}
