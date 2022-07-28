#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

extern char **environ;

int check_mode(void);
char *_getenv(const char *);

#endif

