#include "shell.h"


// 시스템 시간을
// ctime, time 함수를 이용하면 된다. 

int date(){

    // 시간을 다루는 기본적인 변수 타입
    time_t cur_time = time(NULL);

    printf("%s", ctime(&cur_time));

    return 0;
}
