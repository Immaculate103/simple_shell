/* Includes */
#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

/* Defines */
#define LINE_BUFFER 1024
#define SIZE_OF_BUFFER 64
#define S_REDIR 2
#define S_PIPE 3
/* #define S_HIST 128 */
/* #define CMD_LEN_MAX 128 */

/* #define F_PROMPT "%Y-%m-%d %H:%M:%S " */
#define M_L_PROMPT 30

#define D_FILE ">"
#define A_FILE ">>"
#define F_FILE "<"
#define P_CHOICE "|"

/* Globals */
int T_run;
/* Initializes the shell */
void ss_init();
/* Return the current working directory */
char *dir_get();
/* Initialization in terms of time */
char *prompt_entry();
/* Error reporting */
void error_h(char *msg);
/* Remove new line character from the end of a string*/
void remove_null_term_char(char *line);
/* handles prints */
int k_puts(const char *s);
/* Reads a string from the stdin */
void l_reader(char *line);
/* Parse the input string into arguments */
void cmd_parser(char *input_string, char **argv, int *wait);
/* Determines if a command has input output re-direction */
int redir_tr(char **argv);
/* Check if an argument contains pipe option */
int pipe_tr(char **argv);
/* parses and redirects arguments */
void redir_parser(char **argv, char **redirect_argv, int redirect_index);
/* parses and executes piped commands */
void p_parser(char **argv, char **child01_argv, char **child02_argv, int pipe_index);
/* Executes a child process */
void ch_ex(char **argv);
/* Execute a child process and overwrite input from a file */
void ch_ovwrt_ex(char **argv, char **dir);
/* execute a child process and overwrite output to a file */
void ch_ovwrt_ex_f(char **argv, char **dir);
/* Executes a child process and appends to output to file */
void ch_ex_a_f(char **argv, char **dir);
/* Executes a child process that reads input from the main process */
void ch_p_ex(char **argv_in, char **argv_out);
void exec_parent(pid_t child_pid, int *bg);
/* Set the value of the previous command to the given line of input */
void set_prev_command(char *history, char *line);
/* Retrive the previous command from history */
char *get_prev_command(char *history);
/* Function declarations for builtin commands */

/* Returns the number of built-in commands in the shell */
int ss_builtins();
/* Changes the current working directory of the shell process */
int ss_cd(char **argv);
/* Print information about the shell and its available commands. */
int ss_help(char **argv);
/* Terminate the shell. */
int ss_exit(char **args __attribute__((unused)));
/* Display previous commands and run them */
int ss_hist(char *history, char **redir_args);
/*  handles input/output redirection in a command */
int ss_redir(char **args, char **redir_argv);
/* Execute command with pipe */
int pipe_ss(char **args);
/* Executes commands inputed */
void cmd_ex(char **args, char **redir_argv, int wait, int res);
#endif
