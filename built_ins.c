#include "main.h"
/**
 * simple_shell_num_builtins - Returns the number of built-in commands
 *
 * Return: The number of built-in commands
 */
/* List of builtin commands */
char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};
/* The corresponding functions */
int (*builtin_func[])(char **) = {
    &ss_cd,
    &ss_help,
    &ss_exit
};
int ss_builtins()
{
    return sizeof(builtin_str) / sizeof(char *);
}
/**
 * ss_cd - Changes the current working directory
 * @argv: array of arguments
 *
 * Return: 1 on success, 0 on failure
 */
int ss_cd(char **argv)
{
    if (argv[1] == NULL)
    {
        fprintf(stderr, "please provide arguments to \"cd\"\n");
    }
    else
    {
        if (chdir(argv[1]) != 0)
        {
            perror("Error: Unable to change the current working directory");
        }
    }
    return (1);
}
/**
 * ss_help - Displays information about built-in commands
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int ss_help(char **argv)
{
    static char help_team_information[] =
        "ALX SIMPLE SHELL PROJECT\n";
        static char help_cd_command[] = "CD COMMAND\n";
    static char help_exit_command[] = "EXIT COMMAND\n";

    if (strcmp(argv[0], "help") == 0 && argv[1] == NULL)
    {
        printf("%s", help_team_information);
        return 0;
    }

    if (strcmp(argv[1], "cd") == 0)
    {
        printf("%s", help_cd_command);
    }
    else if (strcmp(argv[1], "exit") == 0)
    {
        printf("%s", help_exit_command);
    }
    else
    {
        printf("%s", "Error: Too much arguments.");
        return 1;
    }
    return 0;
}
void cmd_ex(char **args, char **redir_argv, int wait, int res)
{
    /* Check if the command matches a built-in command and execute it if it does.*/
	int i;
    for (i = 0; i < ss_builtins(); i++)
    {
        if (strcmp(args[0], builtin_str[i]) == 0)
        {
            (*builtin_func[i])(args);
            res = 1;
        }
    }

    /* Execute non-built-in command */
    if (res == 0)
    {
        int environ_state;

        /* Create child process */
        pid_t pid = fork();
        if (pid == 0)
        {
            /* Child process */
            if (res == 0)
                res = ss_redir(args, redir_argv);
            if (res == 0)
                res = pipe_ss(args);
            if (res == 0)
                execvp(args[0], args);
            exit(EXIT_SUCCESS);
        }
        else if (pid < 0) /* Error occurred while creating child process */
        {
            perror("Error: Error during the creation of a child process");
            exit(EXIT_FAILURE);
        }
        else
        {
            /* Parent process */
            if (wait == 1)
            {
                waitpid(pid, &environ_state, WUNTRACED);
            }
        }
    }
}
