#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/*buffer size*/
#define BUFFER_SIZE 1024
#define FLUSH_BUFFER_SIZE -1


/*prototypes*/
int s_strlen(int *s);
int s_strcmp(const char *str1, const char *str2);
char *s_start_w(const char *str1, const char *str2);
char *s_strcat(char *dest,	char *src);
char *s_strcpy(char *dest, char *src);
char *s_strdup(char *str);
void s_put(char *str);
int s_putchar(char c);
char *s_strncpy(char *dest, char *src, int len);
char *s_strncat(char *dest, char *src, int len);
char *s_strchr(char *dest, char src);

#endif /*SIMPLE_SHELL*/
