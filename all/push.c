#include "../include/checker.h"
#include "../include/all.h"
/*
** take the first element at the top of first pile and put it
** at the top ofsecond pile. Do nothing if the second pile is empty.
*/

void		push(t_list **list1, t_list **list2, char c)
{
	int nb;

	if (DEBUG == 1)
		dprintf(1, "---------- ***** PUSH_%c\n", c);
	if (*list2)
	{
		nb = pop_pile(list2);
		push_pile(list1, nb);
	}
}
