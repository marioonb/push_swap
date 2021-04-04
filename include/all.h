#ifndef ALL_H
# define ALL_H
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
void				push_pile(t_list **list, int val);
void				push_pile(t_list **list, int val);
void				check_error(char **tab);
void				affiche_2(t_list *list, t_list* l2);
#endif
