/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_in_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/all.h"

static int	max_in_queue2(int *tab, int t, int *max)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	*max = -2147483648;
	while (i < t)
	{
		if (tab[i] > *max)
		{
			res = i;
			*max = tab[i];
		}
		i++;
	}
	if (DEBUG == 1)
		dpf(1, "Partie 2 de la pile : position du max = %d --->", res);
	return (res);
}

int			max_in_queue(t_list *b, int size, int *max)
{
	int		i;
	int		*tab;
	int		size2;

	i = 0;
	size2 = size / 2;
	while (size - size2 > i)
	{
		b = b->next;
		i++;
	}
	tab = copy_in_tab(b);
	size = max_in_queue2(tab, size2, max);
	free(tab);
	return (size);
}

static int	find_element_bloc_in_queue2(int *tab, int nb, int *bloc, int t)
{
	int		i;
	int		j;

	j = 0;
	while (j < t)
	{
		i = 0;
		while (i < nb)
		{
			if (tab[j] == bloc[i])
			{
				if (DEBUG == 1)
				{
					dpf(1, "L'element le plus proche contenu dans le bloc ");
					dpf(1, "actuel et dans la queue est "BL"%d"ST"\n", bloc[i]);
				}
				return (j + 1);
			}
			i++;
		}
		j++;
	}
	return (-1);
}

int			find_element_bloc_in_queue(t_list *a, int nb, int *bloc)
{
	int		i;
	int		compt;
	int		size;
	int		median;
	int		*tab;

	compt = 1;
	i = 0;
	size = ft_lstsize(a);
	median = size / 2;
	while (median > i)
	{
		a = a->next;
		i++;
	}
	tab = copy_in_tab(a);
	compt = find_element_bloc_in_queue2(tab, nb, bloc, size - median);
	free(tab);
	return (compt);
}
