#include "shell.h"

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

