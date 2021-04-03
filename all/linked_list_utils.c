#include "../include/checker.h"

void		affiche_list(t_list *list)
{
	while (list)
	{
		dprintf(1, " %d ", list->nb);
		list = list->next;
	}
}

void		create_list(t_list **list, char **av)
{
	int		i;
	t_list	*new;

	i = 1;
	while (av[i])
	{
		new = ft_lstnew(atoi(av[i]));
		ft_lstadd_back(list, new);
		i++;
	}
}

/*
** check if stack are sorted
*/

int			check_sort(t_list *lista, t_list *listb)
{
	if (listb != NULL)
		return (0);
	while (lista && lista->next)
	{
		if (lista->next->nb < lista->nb)
			return (0);
		lista = lista->next;
	}
	return (1);
}
