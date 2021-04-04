#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../include/all.h"

# ifndef DEBUG
#  define DEBUG 0
# endif




void				ft_lstadd_back(t_list **alst, t_list *new);
t_list				*ft_lstnew(int val);
int					pop_pile(t_list **list);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				create_list(t_list **list, char **av);
void				affiche_list(t_list *list);
void				algo_for_three(t_list **l, t_list **lb);
void				insert_int(t_list **lista, t_list **lb);
void				algo_for_five(t_list **lista, t_list **listb);
int					search_next_min(t_list *list, int index);
int					is_min (int nb, t_list *list);
int					is_max(int nb, t_list *list);
int					search_min(t_list *list);
int					reverse_sort(t_list **list);
void				execute(char *s, t_list **a, t_list **b);
int					ft_lstsize(t_list *lst);
int					check_sort_stack(t_list **lista);
void				algo_for_hundred(t_list **a, t_list **b);
