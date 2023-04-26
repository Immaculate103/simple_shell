#include "main.h"
/**
 * ch_ex_a_f - Executes a child process with output.
 * @arg_vect: Array of strings containing the command and its arguments.
 * @dest: Array of strings containing the redirection arguments.
 */
void ch_ex_a_f(char **arg_vect, char **dest)
{
	int output_fd = -1;

	if (access(dest[0], F_OK) != -1)

	{
		output_fd = open(dest[0], O_WRONLY | O_APPEND);
	}
	if (output_fd == -1)
	{
		perror("Error: REDIRECTION TO OUTPUT FAILED");
		exit(EXIT_FAILURE);
	}
	dup2(output_fd, STDOUT_FILENO);
	if (close(output_fd) == -1)
	{
		perror("Error: CLOSING FAILED");
		exit(EXIT_FAILURE);
	}
	ch_ex(arg_vect);
}

/**
 * ch_p_ex - Performs communication between two commands via Pipe
 * @argsin: array of arguments for child 1
 * @argsout: array of arguments for child 2
 *
 * Return: void
 */
void ch_p_ex(char **argsin, char **argsout)
{
	int f_desc[2];

	if (pipe(f_desc) == -1)

	{
		perror("Error: Piping failed");
		exit(EXIT_FAILURE);
	}


	if (fork() == 0)
	{
		dup2(f_desc[1], STDOUT_FILENO);
		close(f_desc[0]);
		close(f_desc[1]);
		ch_ex(argsin);
		exit(EXIT_SUCCESS);
	}


	if (fork() == 0)
	{
		dup2(f_desc[0], STDIN_FILENO);
		close(f_desc[1]);
		close(f_desc[0]);
		ch_ex(argsout);
		exit(EXIT_SUCCESS);
	}

	close(f_desc[0]);
	close(f_desc[1]);
	wait(0);
	wait(0);
}
