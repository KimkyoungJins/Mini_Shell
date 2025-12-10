#include "shell.h"

int pwd(){
    
    char *cur_dir;

    cur_dir = getcwd(NULL, 0);

    printf("%s\n", cur_dir);
    free(cur_dir);

    return 0;
}
