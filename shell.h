#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
// #include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

/* signal func */
void (*signal(int sig, void (*func)(int)))(int);

/* cmd code */
#define NORM_CMD	0
#define OR_CMD		1
#define AND_CMD		2
#define CHAIN_CMD	3


/* buffer size */
#define BUFFER_SIZE 1024
#define FLUSH_BUFFER_SIZE -1

/* convert Number */
#define converNum_lower 1
#define convertNumber_positive 2

/* line func */
#define GETLINE 0
#define STRTOK 0

/* hist file */
#define FILE_HIST ".simple_shell"
#define MAX_HIST	4096

/* prototypes */

/*s_func_1*/
int s_strlen(char *s);
char *s_strcpy(char *dest, char *src);
char *s_strncat(char *dest, char *src, int len);
int s_putfd(char s, int file);
int s_putsfd(char *s, int file);

/*s_func_2*/
char *s_strcat( char *dest,  char *src);
char *s_strchr(char *dest, char src);
char *s_strncpy(char *dest, char *src, int len);
int s_strcmp(const char *str1, const char *str2);

/* s_func_3*/
void s_put(char *str);
int s_putchar(char c);
char *s_start_w(const char *str1, const char *str2);
char *s_strdup(char *str);

/* s_func_4*/
char *convert_num(long int n, int start, int end);
int delim_is(char c, char *del);
char **s_strtow(char *str, char *ptr);
char *char_dup(char *pathstr, int in, int to);




/* linked list */
/**
 * struct node - Entry point
 * @n: Number
 * @s: String
 * @next: Pointer
 * Return: (0)
*/
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
ssize_t get_index_node(node_t *hhead, node_t *nnode);

/* link_list_2 */
node_t *add_node_end(node_t **head, char *str, int num);
void free_node(node_t **head);
size_t s_list_len(node_t *h);
char **s_list_to_str(node_t *head);
node_t *node_start_w(node_t *node, char *pro, char s);





/* data struct */

/**
 * struct data - Entry point 
 * @arg: pointer 
 * @argv: pointer
 * @path: pointer
 * @argc: Number
 * @line_count: Number
 * @err_num: Number
 * @line_count_flag: Number
 * @fname: pointer
 * @env: pointer
 * @environ: pointer
 * @history: node
 * @alias: node
 * @env_changed: pointer
 * @status: int
 * @cmd_buf: pointer
 * @cmd_buf_type: pointer
 * @read_fd: tpointer
 * @hist_count: pointer
 * Return: (0)
 */
typedef struct data
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int line_count_flag;
	char *fname;
	node_t *env;
	node_t *history;
	node_t *alias;
	char **environs;
	int env_changed;
	int status;
	char **cmd_buf;
	int cmd_buf_type;
	int read_fd;
	int hist_count;
} data_t;

#define DATA_INFO \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}


/* built_in */
int s_exitme(data_t *data);
int s_helpme(data_t *data);
int builtin_find(data_t *data);
int s_cdme(data_t *data);
/**
 * struct built_n - Entry point for
 * @type: character
 * @func: function
 * Return: (0)
*/
typedef struct built_n
{
	char *type;
	int (*func)(data_t *);
} builtin_t;



/* enverion function */
int s_env_list(data_t *info);
int s_envme(data_t *data);
int s_env_set(data_t *data, char *let, char *result);
int s_set_envme(data_t *data);
int s_un_setenv(data_t *data, char *let);
int s_un_setenvme(data_t *data);
char **environ_get(data_t *data);
char *s_getenv(data_t *data, const char *host);



/* memory function */
char *s_memset(char *s, char b, unsigned int n);
void *s_realloc(void *ptrr, unsigned int size_old, unsigned int size_new);



/* free func */
void freee(char **ptr);
int freeb(void **p);
void list_free(node_t **new_head);



/* info func */
void clear_data(data_t *data);
ssize_t get_info(data_t *data);
ssize_t input_buffer(data_t *data, char **buffer, size_t *length);
void set_data(data_t *data, char **av);
void free_data(data_t *data, int all);


/* interactive mood function */
int interactive_mood(data_t *data);


/* line func*/
ssize_t read_buffer(data_t *data, char *buffer, size_t *digit);
void sigint_Handel(__attribute__((unused))int num);
int s_getline(data_t *data, char **ptr, size_t *len);
void comment_remove(char *buffer);


/* his func */
char *get_his(data_t *data);
int s_histme(data_t *data);
int his_renum(data_t *data);
int build_his_list(data_t *data, char *buffer, int line);
int his_write(data_t *data);
char *get_his_file(data_t *data);
int read_his(data_t *data);

/* cheack */
void check_i(data_t *data, char *buffer, size_t *ptr, size_t j, size_t lenght);
int is_cheak(data_t *data, char *buffer, size_t *ptr);


/* alias1 func */
int str_rep(char **old_str, char *new_str);
int alias_replace(data_t *data);
int var_replace(data_t *data);
int alias_print(node_t *head);

/* alias2 func */
int s_alias_unset(data_t *data, char *s);
int s_alias_set(data_t *data, char *s);
int s_aliasme(data_t *data);

/* ERROR function */
int s_eputchar(char c);
void s_eput(char *s);
int s_err_atoi(char *str);
int print_e(int in, int file);
void error_print(data_t *data, char *str);


/* cmd func */
void cmd_fork(data_t *data);
int cmd_is(data_t *data, char *lol);
void cmd_find(data_t *data);

/* path func */
char *path_find(data_t *data, char *str, char *cd);


/* hsh func */
int hsh(data_t *data, char **argv);


#endif /*SIMPLE_SHELL*/
