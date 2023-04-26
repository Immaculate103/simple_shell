#include "main.h"

/**
 * ss_init - Initializes the shell
 */
void ss_init(void)
{
    char *name_of_prog = getenv("USER");
    puts("\nCurrent user: @");
    puts(name_of_prog);
    puts("");
}
