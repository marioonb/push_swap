/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/all.h"

static void	best_is_queue(t_list **a, t_list **b, int index, int debug)
{
	if (DEBUG == 1)
	{
		dprintf(1, "La valeur %d etant la plus grande, on la recupere", debug);
		dprintf(1, " par le bas avec %d rotations a droite\n", index + 1);
	}
	while (index + 1 > 0)
	{
		execute("rrb", a, b);
		index--;
	}
}

static void	best_is_head(t_list **a, t_list **b, int index, int debug)
{
	if (DEBUG == 1)
	{
		dprintf(1, "La valeur %d etant la plus grande, on le recupere", debug);
		dprintf(1, " par le haut avec %d rotations a gauche\n", index);
	}
	while (index > 0)
	{
		execute("rb", a, b);
		index--;
	}
}

void		sort_b_for_end(t_list **a, t_list **b)
{
	int		head_index;
	int		queue_index;
	int		size;
	int		max_head;
	int		max_queue;

	while ((*b) != NULL)
	{
		size = ft_lstsize((*b));
		head_index = max_in_head((*b), size, &max_head);
		if (DEBUG == 1)
			dprintf(1, " C'est %d\n", max_head);
		queue_index = max_in_queue((*b), size, &max_queue);
		if (DEBUG == 1)
			dprintf(1, " C'est %d\n", max_queue);
		if (max_head < max_queue)
			best_is_queue(a, b, queue_index, max_queue);
		else
			best_is_head(a, b, head_index, max_head);
		if (DEBUG == 1)
			dprintf(1, "une fois a sa place, on push l'element sur a\n");
		execute("pa", a, b);
	}
	if (DEBUG == 1)
		dprintf(1, "la pile b est vide... et la pile a est triée..\n\n");
}
