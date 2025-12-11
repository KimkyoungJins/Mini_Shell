#include "shell.h"
#include <unistd.h>

int rmdir_command(char **argv) {
    if (argv[1] == NULL) {
        return 1;
    }
    
    rmdir(argv[1]);

    return 0;
}
