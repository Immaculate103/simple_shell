#include "main.h"
/**
 * dir_get - Get the current working directory.
 *
 * Return: Pointer to the current working directory.
 */
char *dir_get() {
    char c_dir[FILENAME_MAX];
    char*rlt = getcwd(c_dir, sizeof(c_dir));
    return rlt;
}

/**
 * prompt_entry - Initializes the Shell prompt
 * @param None
 * @return A pointer to the prompt string
 */
char *prompt_entry() {
    static char *_prompt = NULL;
    char* username;

    if (_prompt == NULL) {
        _prompt = malloc(M_L_PROMPT * sizeof(char));
        if (_prompt == NULL) {
            perror("Error: Unable to allocate memory");
            exit(EXIT_FAILURE);
        }
    }

    /* Clear prompt */
    memset(_prompt, 0, M_L_PROMPT);

    /* Append default shell name */
    username = getenv("USER");
    strncat(_prompt, username, strlen(username));

    return _prompt;
}
