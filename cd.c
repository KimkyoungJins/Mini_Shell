#include "shell.h"
#define DIRPATHSIZE 1024


/*
 * getenv(), chdir(), getcwd() 시스템콜 사용
 */

int cd(char **argv){

    if(argv[1] == NULL){
        perror("Wrong command\n");
        return 1;
    }
    
    if(chdir(argv[1]) !=  0){
        perror("Change dir failed\n");
        return 1;
    }

   
    return 0;
}
