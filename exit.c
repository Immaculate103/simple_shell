#include "main.h"
/**
 * ss_exit - Exits the shell by setting the running flag to 0.
 * @args: An array of strings containing the arguments passed to the exit command.
 *
 * Return: 0 (not used).
 */
int ss_exit(char **args __attribute__((unused))) {
    T_run = 0;
    return T_run;
}
