#include "main.h"
/**
 * dir_get - Get the current working directory.
 *
 * Return: Pointer to the current working directory, on failure NULL.
 */

char *dir_get(void)
{
	char c_dir[FILENAME_MAX];
	char *rlt = getcwd(c_dir, sizeof(c_dir));

	return (rlt);
}

/**
 * prompt_entry - Initializes the Shell prompt
 *
 * Return: A pointer to the prompt string
 */
char *prompt_entry(void)
{
	static char *prompt;
	char *username;

	if (!prompt)
	{
		prompt = malloc(M_L_PROMPT * sizeof(char));
		if (!prompt)
		{
			perror("Error: Unable to allocate memory");
			exit(EXIT_FAILURE);
		}
	}

	/* Clear prompt */
	memset(prompt, 0, M_L_PROMPT);

	/* Append default shell name */
	username = getenv("USER");
	strncat(prompt, username, strlen(username));

	return (prompt);
}
