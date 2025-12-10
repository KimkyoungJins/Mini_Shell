#include "shell.h"


int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit"))
        exit(0);

    // 백그라운드 작업일시에
    if (!strcmp(argv[0], "&"))
        return 1;
    return 0; // 내장 명령어가 아님
}

