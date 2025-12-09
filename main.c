/* shellex.c */
/* 기본 헤더 파일 포함 필요: stdio.h, stdlib.h, string.h, unistd.h, sys/wait.h 등 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys.wait.h>

#define MAXLINE 8192 /* Max text line length */
#define MAXARGS 128

/* Function prototypes */
void eval(char *cmdline);
int parseline(char *buf, char **argv);
int builtin_command(char **argv);
void display_file_info(const char *path, const struct dirent *entry);

extern char **environ; /* Defined by libc */

int main()
{
    char cmdline[MAXLINE];
    while (1) {
        /* read */
        printf("> "); // 과제에서는 "% "로 변경 필요
        fgets(cmdline, MAXLINE, stdin);
        if (feof(stdin))
            exit(0);
        /* evaluate */
        eval(cmdline);
    }
}

/* eval */
void eval(char *cmdline)
{
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE]; /* Holds modified command line */
    int bg; /* Should the job run in bg or fg? */
    pid_t pid; /* Process id */
    
    strcpy(buf, cmdline);
    bg = parseline(buf, argv);
    
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
    return;
}

/* builtin - 내장 명령어 처리 */
int builtin_command(char **argv)
{
    if (!strcmp(argv[0], "quit"))
        exit(0);
    if (!strcmp(argv[0], "&"))
        return 1;
    return 0; // 내장 명령어가 아님
}

/* parseline - 명령어 파싱 */
int parseline(char *buf, char **argv)
{
    char *delim; /* Points to first space delimiter */
    int argc; /* Number of args */
    int bg; /* Background job? */
    
    buf[strlen(buf)-1] = ' ';
    while (*buf && (*buf == ' '))
        buf++;
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
        argv[argc++] = buf;
        *delim = '\0';
        buf = delim + 1;
        while (*buf && (*buf == ' '))
            buf++;
    }
    argv[argc] = NULL;
    
    if (argc == 0)
        return 1;
        
    if ((bg = (*argv[argc-1] == '&')) != 0)
        argv[--argc] = NULL;
        
    return bg;
}

