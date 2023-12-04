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

/* convert Number */
#define convertNumber_lowercase 1
#define convertNumber_positive 2



/*prototypes*/

/*s_func_1*/
int s_strlen(int *s);
char *s_strcpy(char *dest, char *src);
char *s_strdup(char *str);
char *s_strncat(char *dest, char *src, int len);

/*s_func_2*/
char *s_strcat(char *dest,	char *src);
char *s_strchr(char *dest, char src);
char *s_strncpy(char *dest, char *src, int len);
int s_strcmp(const char *str1, const char *str2);

/* s_func_3*/
void s_put(char *str);
int s_putchar(char c);
char *s_start_w(const char *str1, const char *str2);

/* s_func_4*/
char *convert_num(long int n, int start, int end);


/* memory function */
char *s_memset(char *s, char b, unsigned int n);


/* linked list */
typedef struct node
{
	int n;
	char *s;
	struct node *next;
} node_t;

/* link_list_1 */
size_t print_node_list(const node_t *h);
size_t printf_node_list(const node_t *h);
int del_node_index(node_t **head, unsigned int index);
node_t *add_node_head(node_t **head, char *str, int num);

/* link_list_2 */
node_t *add_node_end(node_t **head, char *str, int num);
void free_node(node_t **head);
size_t s_list_len(node_t *h);
char **s_list_to_str(node_t *head);/*s_func_1*/
int s_strlen(int *s);
char *s_strcpy(char *dest, char *src);
char *s_strdup(char *str);
char *s_strncat(char *dest, char *src, int len);

/*s_func_2*/
char *s_strcat(char *dest,	char *src);
char *s_strchr(char *dest, char src);
char *s_strncpy(char *dest, char *src, int len);
int s_strcmp(const char *str1, const char *str2);

/* s_func_3*/
void s_put(char *str);
int s_putchar(char c);
char *s_start_w(const char *str1, const char *str2);

/* s_func_4*/
char *convert_num(long int n, int start, int end);


/* memory function */
char *s_memset(char *s, char b, unsigned int n);


/* linked list */
typedef struct node
{
	int n;
	char *s;
	struct node *next;
} node_t;

/* link_list_1 */
size_t print_node_list(const node_t *h);
size_t printf_node_list(const node_t *h);
int del_node_index(node_t **head, unsigned int index);
node_t *add_node_head(node_t **head, char *str, int num);

/* link_list_2 */
node_t *add_node_end(node_t **head, char *str, int num);
void free_node(node_t **head);
size_t s_list_len(node_t *h);
char **s_list_to_str(node_t *head);


#endif /*SIMPLE_SHELL*/
