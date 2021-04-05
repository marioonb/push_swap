/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_hundred.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/all.h"

static int	*create_bloc(t_list *list, int nb, int *current)
{
	int		*bloc;
	int		i;

	bloc = malloc(sizeof(int) * nb);
	i = 0;
	while (i < nb)
	{
		bloc[i] = search_next_min(list, *current);
		*current = bloc[i];
		i++;
	}
	return (bloc);
}

static void	ft_debug_hundred(int pos, int pos2, int *bloc, int nb)
{
	dprintf(1, "les element qu'on chercher etant actuellement : ");
	ft_read_tab_int(bloc, nb);
	if (pos - 1 > pos2 && pos2 != -1)
	{
		dprintf(1, "C'est donc celui de la %s le plus petit\n", "queue");
		dprintf(1, "sa position est %d\n", pos2);
		dprintf(1, "nous allons donc faire %d rotations a droite\n", pos2);
	}
	else
	{
		dprintf(1, "C'est celui de la tete qui demande le moins d'action\n");
		dprintf(1, "sa position est %d\n", pos - 1);
		dprintf(1, "nous allons donc faire %d rotations a gauche\n", pos - 1);
	}
	dprintf(1, "puis push sur la pile b");
}

static void	exec_algo_hundred(int *bloc, t_list **a, t_list **b, int nb)
{
	int		head;
	int		queue;
	int		i;

	i = 0;
	while (i < nb && (*a))
	{
		head = find_element_bloc_in_head((*a), nb, bloc);
		queue = find_element_bloc_in_queue((*a), nb, bloc);
		if (DEBUG == 1)
			ft_debug_hundred(head, queue, bloc, nb);
		if (head - 1 > queue && queue != -1)
		{
			while (queue-- > 0)
				execute("rra", a, b);
		}
		else
		{
			while (head-- - 1 > 0)
				execute("ra", a, b);
		}
		execute("pb", a, b);
		i++;
	}
}

void		algo_for_hundred(t_list **a, t_list **b, int size, int val)
{
	int		nb;
	int		*bloc;
	int		current;
	int		i;

	i = 0;
	nb = size / val;
	if (size % val)
		nb += 1;
	current = -2147483648;
	while (i < val)
	{
		if (i == val && size % val != 0)
			nb = size % val;
		bloc = create_bloc((*a), nb, &current);
		exec_algo_hundred(bloc, a, b, nb);
		free(bloc);
		i++;
	}
	if (DEBUG == 1)
	{
		dprintf(1, "-----------------------------------\n||           TRI DE ");
		dprintf(1, "B            ||\n-----------------------------------\n\n");
	}
	sort_b_for_end(a, b);
}
