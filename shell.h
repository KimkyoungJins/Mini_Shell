#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>

#define MAXLINE 1024
#define MAXARGS 128

void eval(char *cmdline);

int parseline(char *buf, **argv);

int builtin_cammand(char **argv);
void do_cd(char **argv);

// 추가적인 함수 ...?:

extern char **environ;

#endif
