#include "shell.h"


int cat(char **argv){

    // 저장할 버퍼 포인터
    void *buf;
    
    struct stat *file_stat;

    // 동적 메모리 할당?
    file_stat = (struct stat *)malloc(sizeof(struct stat));

    // 불러온 파일을 읽어온다. 
    int fd = open(argv[1], O_RDONLY);

    if(fd == -1){
        perror("File open failed\n");
        return 1;
    }

    // 파일을 열고 그 정보를 해당 구조체에 넣는다. 
    if(fstat(fd, file_stat) == -1){
        perror("fstat failed\n");
        return 1;
    }
    
    off_t size = file_stat->st_size;

    // 그리고 동적 할당한다. 
    buf = (void *)malloc(sizeof((size_t)size));

    // 파일 리디해서 버퍼에 넣는다.
    if(read(fd, buf, size) == -1){
        perror("File read failed\n");
        return 1;
    }

    int bytes = write(STDOUT_FILENO, buf, (size_t)size);

    if(bytes < 0){
        perror("write failed\n");
        return 1;
    }


    free(buf);
    //free(file_size);
    close(fd);
    return 0;
}
