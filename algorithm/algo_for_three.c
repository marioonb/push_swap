#include "../include/push_swap.h"
#include "../include/all.h"

void algo_for_three(t_list **l, t_list **lb)
{
	t_list *a;

	a = (*l);
	while (check_sort_stack(l) != 1)
	{
		//dprintf(1, "THREE\n");
		a = (*l);
		if (ft_lstsize(a) < 3)
			execute("sa", l, lb);
		else if (((a->nb > a->next->nb || a->nb < a->next->nb) &&
		(a->nb < a->next->next->nb))
		|| reverse_sort(l))
			execute("sa", l, lb);
		else if (a->nb > a->next->nb && a->nb > a->next->next->nb)
			execute("ra", l, lb);
		else if (a->nb < a->next->nb && a->nb > a->next->next->nb)
			execute("rra", l, lb);
	}
}
