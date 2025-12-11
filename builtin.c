#include "shell.h"


int builtin_command(char **argv)
{

    // 주어진 명령어인지.
    if (!strcmp(argv[0], "quit"))
        exit(0);

    // ls 명령어
    // 같으면 0 반환
    else if(!strcmp(argv[0], "ls")){
        ls();
        return 1;
    }

    // cd 명령어
    else if(!strcmp(argv[0], "cd")){
        cd(argv);
        return 1;
    }

    // pwd 명령어
    else if(!strcmp(argv[0], "pwd")){
        pwd();
        return 1;
    } 

    // exit 명령어
    else if(!strcmp(argv[0], "exit") || !strcmp(argv[0], "logout")){
        exit(0);
    }
    
    else if(!strcmp(argv[0], "date")){
        date();
        return 1;
    }

    else if(!strcmp(argv[0], "cat")){
        cat(argv);
        return 1;
    }

    else if(!strcmp(argv[0], "cp")){ 
        return cp_command(argv);
    }

    else if(!strcmp(argv[0], "rm")){
        return rm_command(argv);
    }
    

    // 백그라운드 작업일시에
    if (!strcmp(argv[0], "&"))
        return 1;


    return 0; // 내장 명령어가 아님
}

