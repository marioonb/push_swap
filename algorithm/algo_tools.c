/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/all.h"

int		*copy_in_tab(t_list *a)
{
	int	size;
	int *tab;
	int	i;

	size = ft_lstsize(a);
	tab = malloc(sizeof(int) * size);
	i = size - 1;
	while (i >= 0)
	{
		tab[i] = a->nb;
		a = a->next;
		i--;
	}
	return (tab);
}

int		search_next_min(t_list *list, int index)
{
	int	i;
	int	min;

	min = 2147483647;
	i = 0;
	while (list)
	{
		if (list->nb < min && list->nb > index)
			min = list->nb;
		list = list->next;
	}
	return (min);
}

int		is_min(int nb, t_list *list)
{
	while (list != NULL)
	{
		if (list->nb < nb)
			return (0);
		list = list->next;
	}
	return (1);
}

int		is_max(int nb, t_list *list)
{
	while (list)
	{
		if (list->nb > nb)
			return (0);
		list = list->next;
	}
	return (1);
}

int		search_min(t_list *list)
{
	int	i;
	int	min;

	min = list->nb;
	i = 0;
	while (list)
	{
		if (list->nb < min)
			min = list->nb;
		list = list->next;
	}
	return (min);
}
