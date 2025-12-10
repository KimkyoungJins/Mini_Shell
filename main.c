#include "shell.h"


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
