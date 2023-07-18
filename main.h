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
void exitfunc(char *status);
int findexec(char **environ, char **getlin);
int _strtok(char *prompt, char **getlin, char *delims);
int _getline(char *prompt, int *n);

#endif
