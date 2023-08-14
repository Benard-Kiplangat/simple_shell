#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int main(int argc, char **argv);
void envfunc(void);
char *_strdup(char *str);
int loop(char **getlin, int *cnt);
void exitfunc(int status);
int findexec(char **environ, char *get_token, char **path, char **getlin);
int _strtok(char *prompt, char *token, char **getlin, char *delims);
int _getline(char *prompt);
int cdfunc(char **getlin, int *cnt);
void forkfunc(char **getlin, char **environ, int *cnt);
void errmsg(char **getlin, int *cnt);
int runshfile(char *filename, char **getlin, int *cnt);
ssize_t readshfile(const char *filename, char **buf);

#endif
