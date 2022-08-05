#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

extern char **environ;

char *_getenv(const char *);
char **buff_to_array(char *, char *);
char **check_command(char *, char *);
char *fix_dir(char **, char *);
int check_input(char *);
char *_start_(int);
int free_array(char **);
void print_error(char *, char *);

#endif
