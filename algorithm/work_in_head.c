/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_in_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/all.h"

int		max_in_head(t_list *b, int size, int *max)
{
	int	i;
	int	size2;
	int	res;

	res = 0;
	*max = b->nb;
	size2 = size / 2;
	if (size % 2 != 0)
		size2++;
	i = 0;
	while (i < size2 && b)
	{
		if (b->nb > *max)
		{
			*max = b->nb;
			res = i;
		}
		b = b->next;
		i++;
	}
	if (DEBUG == 1)
		dpf(1, "Partie 1 de la pile : position du max = %d --->", res);
	return (res);
}

int		find_element_bloc_in_head(t_list *a, int nb, int *bloc)
{
	int	i;
	int	compt;

	compt = 1;
	i = 0;
	while (a != NULL)
	{
		i = 0;
		while (i < nb)
		{
			if (a->nb == bloc[i])
			{
				if (DEBUG == 1)
				{
					dpf(1, "L'element le plus proche contenu dans le bloc");
					dpf(1, " actuel et dans la tête est "BL"%d"ST"\n", bloc[i]);
				}
				return (compt);
			}
			i++;
		}
		a = a->next;
		compt++;
	}
	return (-1);
}
