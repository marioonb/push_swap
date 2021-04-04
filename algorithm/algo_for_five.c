
#include "../include/push_swap.h"
#include "../include/all.h"

// 	else if ((*lb)->next && !is_min((*lb)->next->nb, a) && !is_max((*lb)->next->nb, a) && (*lb)->nb < (*lb)->next->nb)
//			execute("sb", lista, lb);
// condition ajouté pour swaper dans le cas de 43612 et avoir 10 coups au lieu de 13.

void insert_int(t_list **lista, t_list **lb)
{
	t_list *a = (*lista);

	if (is_min((*lb)->nb, a) && is_min((*lista)->nb, a))
		execute("pa", lista, lb);
	else if (is_max((*lb)->nb, a) && is_min((*lista)->nb, a))
	{
		execute("pa", lista, lb);
		execute("ra", lista, lb);
	}
	else if ((*lb)->next && !is_min((*lb)->next->nb, a) && !is_max((*lb)->next->nb, a) && (*lb)->nb < (*lb)->next->nb)
			execute("sb", lista, lb);
	else if ((*lb)->nb > a->nb && (*lb)->nb < a->next->nb)
	{
		execute("pa", lista, lb);
		execute("sa", lista, lb);
	}
	else
		execute("rra", lista, lb);
}

void 	algo_for_five(t_list **lista, t_list **listb)
{
	t_list *a = (*lista);
	t_list *b;
	int i = 0;
	int nb_min;

	nb_min = search_min(a);
	int size = ft_lstsize(a);
	while ((size > 3))
	{
		execute("pb", lista, listb);
		size--;
	}
	algo_for_three(lista, listb);
	a = (*lista);
	b = (*listb);
	while ((*listb) != NULL && i < 10)
	{
		insert_int(lista, listb);
		i++;
	}
	while ((*lista)->nb > nb_min)
		execute("rra", lista, listb);
}
