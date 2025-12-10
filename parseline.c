#include "shell.h"

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

