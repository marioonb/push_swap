#include "../include/checker.h"

int		ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int reverse_sort(t_list **list)
{
	t_list *a;

	a = (*list);
	while (a && a->next)
	{
		if (a->next->nb > a->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

void		affiche_2(t_list *list, t_list* l2)
{
	dprintf(1, "\nA = ");
	while (list)
	{
		dprintf(1, " %d ", list->nb);
		list = list->next;
	}
	dprintf(1, "\nB = ");
	while (l2)
	{
		dprintf(1, " %d ", l2->nb);
		l2 = l2->next;
	}
	dprintf(1,"\n\n");
}

int			check_sort_stack(t_list **lista)
{
	t_list *a;

	a = (*lista);
	while (a && a->next)
	{
		if (a->next->nb < a->nb)
			return (0);
		a = a->next;
	}
	return (1);
}


void execute(char *s, t_list **a, t_list **b)
{
	dprintf(1, "%s\n", s);
	appli_instruct(s, a , b);
	if (DEBUG == 1)
	{
		affiche_2((*a), (*b));
	}
}

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

int is_min (int nb, t_list *list)
{
	while (list != NULL)
	{
		if (list->nb < nb)
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_max(int nb, t_list *list)
{
	while (list)
	{
		if (list->nb > nb)
			return (0);
		list = list->next;
	}
	return (1);

}
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

int search_min(t_list *list)
{
	int i;
	int min;

	min = list->nb;
	i = 0;

	if (!list)
		return (0);
	while (list)
	{
		if (list->nb < min)
			min = list->nb;
		list = list->next;
	}
	//dprintf(1, "le nombre minimin cest %d ", min);
	return (min);

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

void find_type_sort(t_list **lista, t_list **listb)
{
	int size = ft_lstsize(*lista);
	//dprintf(1, "la size est de %d\n", size);
	if (size <= 3)
		algo_for_three(lista, listb);
	else if (size <= 5)
		algo_for_five(lista, listb);
	else if (size <= 100)
		printf("il a moins de 100\n");
	else if (size <= 500)
		printf("il y a moins de 500\n");
	else if (size <= 100)
		printf("il a moins + de 500\n");
}

int			main(int ac, char **av)
{
	int		i;
	t_list	*lista;
	t_list	*listb;
	char	*buffer;

	(void)ac;
	i = 0;
	lista = NULL;
	listb = NULL;
	buffer = NULL;
	check_error(av);
	create_list(&lista, av);
	if (DEBUG == 1)
	{
		dprintf(1, "\nLISTE AVANT DE DEPART \nA = ");
		affiche_list(lista);
		dprintf(1, "\nB = ");
		affiche_list(listb);
		dprintf(1, "\n");
	}
	find_type_sort(&lista, &listb);
	if (DEBUG == 1)
		affiche_list(lista);
}
