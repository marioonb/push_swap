#ifndef ALL_H
# define ALL_H
#include "../libft/libft.h"
#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <limits.h>
#define INT_MAX_C "2147483647"
#define INT_MIN_C "-2147483648"

# ifndef DEBUG
#  define DEBUG 0
# endif

int g_debug_bonus;

typedef struct		s_list
{
	int				nb;
	struct s_list	*next;
}					t_list;

void				swap(t_list **list, char s);
void				swap_ab(t_list **lista, t_list **listb);
void				appli_instruct(char *line, t_list **lista, t_list **listb);
void				invers_rotate(t_list **list, char c);
void				invers_rotate_ab(t_list **lista, t_list **listb);
void				push(t_list **lista, t_list **listb, char c);
void				rotate(t_list **list, char c);
void				rotate_ab(t_list **lista, t_list **listb);
void				push_pile(t_list **list, int val);
void				push_pile(t_list **list, int val);
void				check_error(char **tab);
void				affiche_2(t_list *list, t_list* l2);
void				algo_for_more(t_list **a, t_list **b);
void				ft_lstadd_back(t_list **alst, t_list *new);
t_list				*ft_lstnew(int val);
int					pop_pile(t_list **list);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				create_list(t_list **list, char **av);
void				affiche_list(t_list *list);
void				appli_instruct(char *line, t_list **lista, t_list **listb);
int					check_sort(t_list *lista, t_list *listb);
void				execute(char *s, t_list **a, t_list **b);//
#endif
