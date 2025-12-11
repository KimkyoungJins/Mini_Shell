#include "shell.h"
#include <unistd.h>

int rm_command(char **argv) {
    if (argv[1] == NULL) {
        return 1;
    }
 
    unlink(argv[1]);

    return 0;
}
