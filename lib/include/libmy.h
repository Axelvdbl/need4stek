/*
** libmy.h for ok in /home/alexandre/Documents/lib/my_lib/lib/include/
**
** Made by Alexandre Chamard-bois
** Login   <alexandre.chamard-bois@epitech.eu@epitech.eu>
**
** Started on  Wed Apr 12 20:19:13 2017 Alexandre Chamard-bois
** Last update Wed May 31 08:49:25 2017 Alexandre Chamard-bois
*/

#include "macro.h"

#ifndef LIBMY_H_
# define LIBMY_H_

#ifdef ASC
# undef ASC
#endif
#define ASC 1
#ifdef DESC
# undef DESC
#endif
#define DESC -1

typedef struct  s_list
{
  void          *data;
  struct s_list *next;
  struct s_list *prev;
}               t_list;
typedef int (*t_list_cmp)(void *, void *);
typedef void (*t_list_free)(void *);

// GETLINE //
char    *get_next_line(const int fd);

// SCANF //
int my_scanf(char *format, ...);

// PRINTF //
int     my_printf(const char *str, ...);
int     my_dprintf(const int fd, const char *str, ...);
char    *my_sprintf(const char *str, ...);

// LIST //
t_list    *sort_list(t_list *list, int (*cmp)(void *, void *), int direction);
t_list    *remove_node(t_list *list, void (*free_node)(void *));
t_list    *free_list(t_list *list, void (*free_node)(void *));
t_list    *find_node(t_list *list, void *data, t_list_cmp cmp);
int       nb_node(t_list *list);
int       swap_node(t_list *node1, t_list *node2);
t_list    *new_node(t_list *list, void *data);
t_list    *goto_startlist(t_list *list);
t_list    *goto_endlist(t_list *list);
t_list    *movein_list(t_list *list, const int n);
t_list    *goto_nlist(t_list *list, const int n);

// PUT //
void	  my_putchar(const char c);
void	  my_puts(const char *str);
void	  my_putstr(const char *str);
void	  my_putnbr(const int nb);
void	  my_putnbr_base(const int nb, const char *base);
void    my_showmem(const char *str, const int size);
void    my_show_wordtab(char **tab);

// GET //
int	    my_getnbr(const char *str);
int     my_getnbr_base(const char *str, const char *base);
double	my_atof(const char *str);

// CMP //
int	    my_strcmp(const char *s1, const char *s2);
int	    my_strncmp(const char *s1, const char *s2, int n);
int     my_wordcmp(char *s1, char *s2);
int     my_memcmp(const void *str1, const void *str2, const int size);

// CPY //
char    *my_strcpy(char *dest, const char *src);
char    *my_strncpy(char *dest, const char *src, const int n);
void    *my_memcpy(void *dest, const void *src, const int size);

// CAT //
char    *my_strcat(const char *first, const char *second);
char    *my_strncat(const char *first, const char *second, const int n);
char    *my_concat(const int nb, ...);

// DUP //
char    *my_strdup(const char *str);
char    *my_strndup(const char *str, const int size);
char 		*my_worddup(const char *str);
char 		**my_tabdup(const char **tab);
char    *my_strtok(const char *str, const char *c);
char    *my_split(char *str, int *who, const int nb, ...);
char    **my_str_to_wordtab(const char *str);
char		**my_wordtab(char *str);
void    *my_memdup(const void *ptr, const int size);

// NBs //
int	    my_find_prime_sup(const int nb);
int	    my_is_prime(const int nb);
int	    my_power_rec(const int nb, const int p);
int	    my_sort_int_tab(int *array, const int size);
int	    my_square_root(const int nb);
int     my_nb_line(const char **tab);

// STR //
int	    my_strlen(const char *str);
int	    my_tablen(char **tab);
int	    nb_word(const char *str);
int	    size_word(const char *str);
char    *clean_line(char *str);
char    *my_revstr(char *str);
char    *my_strcapitalize(char *str);
int	    my_str_isalpha(const char *str);
int	    my_str_islower(const char *str);
int	    my_str_isnum(const char *str);
int     my_is_float(const char *str);
int	    my_str_isprintable(const char *str);
int	    my_str_isupper(const char *str);
char    *my_strlowcase(char *str);
char    *my_strupcase(char *str);
char    my_strstr(const char *str, const char *to_find);
int	    my_swap(void **, void **);
void    my_memset(void *data, const char type, const int size);
int	    match(char *s1, char *s2);
int	    nmatch(char *s1, char *s2);

// FREE //
char    *free_tab(char **tab);

#endif
