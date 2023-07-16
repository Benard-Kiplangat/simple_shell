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
int _strtok(char *prompt, char **toks);
int _getline(char *prompt, int *n);
 
#endif
