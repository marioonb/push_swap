
#include "../include/checker.h"
#include "../include/all.h"
/*
** shift up all elements of stack by 1. The first element becomes
** the last one.
*/

void		rotate(t_list **list, char c)
{
	int		val;
	t_list	*new;

	if (DEBUG == 1)
		printf("---------- ***** ROTATE_%c\n", c);
	if ((*list) != NULL)
	{
		val = pop_pile(list);
		new = ft_lstnew(val);
		ft_lstadd_back(list, new);
	}
}

/*
** call rotate for 2 stack.
*/

void		rotate_ab(t_list **lista, t_list **listb)
{
	rotate(lista, 'A');
	rotate(listb, 'B');
}
