#include "main.h"
/**
 * main - The main function, entry point
 * Return: If successful, return 0
 */
int main(void) {
	 /* Array to hold program arguments */
char *prog_args[SIZE_OF_BUFFER];

/* Input */
char pro_input[LINE_BUFFER];

/* Copy of the input line */
char t_pro_input[LINE_BUFFER];

/* Command history */
char prog_hist[LINE_BUFFER] = "commands are absent in history";

/* To hold arguments for Input-output re-direction */
char *ar_vec_read[S_REDIR];

/* Flag to check if command should wait for child process */
int ch_wait;

/* Exit status of previous command */
int prog_results;
T_run = 1;

ss_init();

prog_results = 0;

/* Entering the infinite loop */
while (T_run) {
    printf("%s:%s> ", prompt_entry(), dir_get());
    fflush(stdout);

    /* read input line */
    l_reader(pro_input);

    /* Copy the input line */
    strcpy(t_pro_input, pro_input);

    /* parse the input line */
    cmd_parser(pro_input, prog_args, &ch_wait);

    /* Execute the commands */
    if (strcmp(prog_args[0], "!!") == 0) {
        prog_results = ss_hist(prog_hist, ar_vec_read);
    } else {
        set_prev_command(prog_hist, t_pro_input);
        cmd_ex(prog_args, ar_vec_read, ch_wait, prog_results);
    }
    prog_results = 0;
}
return (0);
}
