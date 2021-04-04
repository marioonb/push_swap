/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/all.h"

/*
** 	else if ((*lb)->next && !is_min((*lb)->next->nb, a) &&
** !is_max((*lb)->next->nb, a) &&
** (*lb)->nb < (*lb)->next->nb)
** execute("sb", lista, lb);
** condition ajouté pour swaper dans le cas de 43612 et avoir 10 coups
** au lieu de 13.
*/

static void	insert_int(t_list **lista, t_list **lb)
{
	t_list	*a;

	a = (*lista);
	if (is_min((*lb)->nb, a) && is_min((*lista)->nb, a))
		execute("pa", lista, lb);
	else if (is_max((*lb)->nb, a) && is_min((*lista)->nb, a))
	{
		execute("pa", lista, lb);
		execute("ra", lista, lb);
	}
	else if ((*lb)->next && !is_min((*lb)->next->nb, a) &&
		!is_max((*lb)->next->nb, a) && (*lb)->nb < (*lb)->next->nb)
		execute("sb", lista, lb);
	else if ((*lb)->nb > a->nb && (*lb)->nb < a->next->nb)
	{
		execute("pa", lista, lb);
		execute("sa", lista, lb);
	}
	else
		execute("rra", lista, lb);
}

void		algo_for_five(t_list **lista, t_list **listb)
{
	t_list	*a;
	t_list	*b;
	int		i;
	int		nb_min;
	int		size;

	i = 0;
	nb_min = search_min((*lista));
	size = ft_lstsize((*lista));
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
