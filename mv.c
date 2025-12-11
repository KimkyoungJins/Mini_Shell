#include "shell.h"
#include <stdio.h>

int mv_command(char **argv) {
    if (argv[1] == NULL || argv[2] == NULL) {
        return 1;
    }
    
    rename(argv[1], argv[2]);

    return 0;
}
