#include "../include/checker.h"
#include "../include/all.h"
/*
** swap the first 2 elements at the top of stack.
** Do nothing if there is only one or no elements).
*/

void	swap(t_list **list, char c)
{
	int	temp;

	if (DEBUG == 1)
		dprintf(1, "---------- ***** SWAP_%c\n", c);
	if (*list != NULL && (*list)->next != NULL)
	{
		temp = (*list)->nb;
		(*list)->nb = (*list)->next->nb;
		(*list)->next->nb = temp;
	}
}

/*
**	call swap for 2 stack.
*/

void	swap_ab(t_list **lista, t_list **listb)
{
	swap(lista, 'A');
	swap(listb, 'B');
}
