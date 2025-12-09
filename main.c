/* shellex.c */
/* 기본 헤더 파일 포함 필요: stdio.h, stdlib.h, string.h, unistd.h, sys/wait.h 등 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>


#define MAXLINE 8192 /* Max text line length */
#define MAXARGS 128

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);
void display_file_info(const char *path, const struct dirent *entry);

extern char **environ; /* Defined by libc */



// ls 명령어 구현
void my_ls(const char *path);

// 메인함수
int main()
{
    char cmdline[MAXLINE];

    while (1) {
        
        // 원래코드에서 %으로 변경함.
        printf("%% ");
        
        // 사용자로부터 입력을 받는다.
        fgets(cmdline, MAXLINE, stdin);

        //feof-> 주어진 문자열이 파일의끝에 도달했는지
        if(feof(stdin))
            exit(0);

        eval(cmdline);
    }
}


// 명령어 처리 함수.
void eval(char *cmdline)
{
    // 명령어 배열?? 
    char *argv[MAXARGS]; /* Argument list execve() */

    // 명령어를 넣을 버퍼
    char buf[MAXLINE]; /* Holds modified command line */
    
    // 백그라운드에서 돌아갈지, 포그라운드에서 돌아갈지
    int bg; /* Should the job run in bg or fg? */

    // 피드 번호
    pid_t pid; /* Process id */
    
    // 커맨드 라인 버퍼에 넣음
    strcpy(buf, cmdline);

    // 커맨드 파싱, 백그라운드 실행여부
    bg = parseline(buf, argv);
    
    // 아무것도 없으면 끝
    if (argv[0] == NULL)
        return;
        
    if (!builtin_command(argv)) {
        if ((pid = fork()) == 0) {
            if (execve(argv[0], argv, environ) < 0) {
                printf("%s: Command not found.\n", argv[0]);
                exit(0);
            }
        }
        if (!bg) {
            int status;
            if (waitpid(pid, &status, 0) < 0)
                perror("waitfg: waitpid error");
        }
        else
            printf("%d %s", pid, cmdline);
    }
}

/* builtin - 내장 명령어 처리 */

// quit이면 끝낸다.
// &이면 백그운드임.
int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit"))
        exit(0);

    // 백그라운드 작업일시에
    if (!strcmp(argv[0], "&"))
        return 1;
    return 0; // 내장 명령어가 아님
}

/* parseline - 명령어 파싱 */
int parseline(char *buf, char **argv)
{

    char *delim; /* Points to first space delimiter */

    // 받은 인자의 수
    int argc; /* Number of args */

    // 백인지 포인지
    int bg; /* Background job? */

    
    // 멘 마지막 개행문자 제거
    buf[strlen(buf)-1] = ' ';

    // 공백이 아닐때까지
    while (*buf && (*buf == ' '))
        buf++;

    argc = 0;
    
    // 매우 효율적인 고전적인 방식이다.
    while ((delim = strchr(buf, ' ')))  {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++;
    }

    argv[argc] = NULL;
    
    // 인자가 하나도 없다면 함수를 종료한다. 
    if (argc == 0)
        return 1;
     
    // 
    if ((bg = (*argv[argc-1] == '&')) != 0)
        argv[--argc] = NULL;
        
    return bg;
}



void my_ls(const char *path){

    DIR *drip = opendir(path);

    if(drip == NULL){
        perror("open dir error\n)";
        return;
    }

}
       

