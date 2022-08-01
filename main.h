#ifndef MAIN_H
#define MAIN_H

#ifndef ARG_MAX
#define ARG_MAX 2097152
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

int check_mode(void);
char *_getenv(const char *);
char **buff_to_array(char *, char *);
char **build_path(char *);
void env_built_in(char**);
void exit_built_in(char**);
char *_start_();

#endif

