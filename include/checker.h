#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <limits.h>
#define INT_MAX_C "2147483647"
#define INT_MIN_C "-2147483648"
#include "../include/all.h"


void				swap(t_list **list, char s);
void				swap_ab(t_list **lista, t_list **listb);
void				appli_instruct(char *line, t_list **lista, t_list **listb);
void				invers_rotate(t_list **list, char c);
void				invers_rotate_ab(t_list **lista, t_list **listb);
void				push(t_list **lista, t_list **listb, char c);
void				rotate(t_list **list, char c);
void				rotate_ab(t_list **lista, t_list **listb);
int					ft_strcmp(char *name, char *value);
void				push_pile(t_list **list, int val);
char				**ft_split(char const*s, char c);
int					ft_atoi(const char *str);
char				*ft_substr(char const *s, unsigned int star, size_t len);
void				push_pile(t_list **list, int val);
void				ft_lstadd_back(t_list **alst, t_list *new);
t_list				*ft_lstnew(int val);
int					pop_pile(t_list **list);
void				ft_lstadd_front(t_list **alst, t_list *new);
void		create_list(t_list **list, char **av);
void		search_operation(char *buffer, t_list **lista, t_list **listb);
int			check_sort(t_list *lista, t_list *listb);
void		affiche_list(t_list *list);
void		appli_instruct(char *line, t_list **lista, t_list **listb);
int			check_sort(t_list *lista, t_list *listb);
int			check_min_and_max(char *s);
int			check_int_type(char *s);

