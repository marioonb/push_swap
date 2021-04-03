#include <string.h>
#include<stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

# ifndef DEBUG
#  define DEBUG 0
# endif


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
void				create_list(t_list **list, char **av);
void				affiche_list(t_list *list);
