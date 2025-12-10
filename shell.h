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
int parseline(char *buf, char  **argv);
int builtin_command(char **argv);
void do_cd(char **argv);
int ls();
int cd(char **argv);
int pwd();

// 추가적인 함수 ...?:

extern char **environ;

