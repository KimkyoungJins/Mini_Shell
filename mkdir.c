#include "shell.h"
#include <sys/stat.h> 

int mkdir_command(char **argv) {
    if (argv[1] == NULL) {
        return 1;
    }
    
    // mkdir(경로, 권한)
    mkdir(argv[1], 0755);

    return 0;
}
