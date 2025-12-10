#include "shell.h"


// opendir, readir, closedir사용
int ls(){

    DIR *cdir;

    // opendir() 함수를 통해서
    // 지금 디렉토리 포인터를 받아온다. 
    cdir = opendir(".");

    if(cdir == NULL){
        perror("Cannot open dir\n");
        exit(1);
    }

    // 정보를 읽어온다. 
    //디렉토리 정보에 대한 구조체
    
    struct dirent *dir;

    while((dir = readdir(cdir)) != NULL){
       
        // ls에서 . 혹은 ..이 나와서
        if(strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0){
            // 반복문의 다음 루프로 이동한다. 
            continue;
        }
                
        printf("%s  ", dir->d_name);
    }

    printf("\n");


    if(closedir(cdir) != 0){
        perror("Failed to close dir\n");
        exit(1);
    }

    return 1;
}

