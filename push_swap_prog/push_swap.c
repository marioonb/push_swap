#include "../include/push_swap.h"
#include "../include/all.h"

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







void find_type_sort(t_list **lista, t_list **listb)
{
	int size = ft_lstsize(*lista);
	//dprintf(1, "la size est de %d\n", size);
	if (size <= 3)
		algo_for_three(lista, listb);
	else if (size <= 5)
		algo_for_five(lista, listb);
	else if (size <= 100)
		//printf("il a moins de 100\n");
		algo_for_hundred(lista, listb);
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
	//create_bloc(lista);
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
