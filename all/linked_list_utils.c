/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

void		affiche_list(t_list *list)
{
	while (list)
	{
		dprintf(1, " %d ", list->nb);
		list = list->next;
	}
}

void		affiche_2(t_list *list, t_list *l2)
{
	dprintf(1, "A = ");
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
	dprintf(1, "\n\n");
}

void		create_list(t_list **list, char **av)
{
	int		i;
	t_list	*new;

	i = 1;
	if(strcmp(av[i], "-v") == 0)
		i++;
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

int			ft_lstsize(t_list *lst)
{
	int		i;

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
