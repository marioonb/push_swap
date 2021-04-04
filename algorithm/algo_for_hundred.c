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

static void	exec_algo_hundred(int *bloc, t_list **a, t_list **b, int nb)
{
	int		head;
	int		queue;
	int		i;

	i = 0;
	while (i < nb)
	{
		head = find_element_bloc_in_head((*a), nb, bloc);
		//dprintf(1, "element de head est position %d\n", head);
		queue = find_element_bloc_in_queue((*a), nb, bloc);
		//dprintf(1, "element de queue est position %d\n", queue);
		if (head - 1 > queue && queue != -1)
		{
			while (queue > 0)
			{
				execute("rra", a, b);
				queue--;
			}
		}
		else
		{
			while (head - 1 > 0)
			{
				execute("ra", a, b);
				//affiche_list((*a));
				head--;
			}
		}
		//affiche_2((*a), (*b));
		execute("pb", a, b);
		//affiche_2((*a), (*b));
		//affiche_list((*a));
		i++;
	}
	//affiche_2((*a), (*b));
}

// envoi de a, b, size et type
//int size = ft_lstsize((*a));
// val= 11 ou 5

void		algo_for_hundred(t_list **a, t_list **b, int size, int val)
{
	int		nb;
	int		*bloc;
	int		current;
	int		i;
	int		end;

	i = 0;
	nb = size / val;
	end = size % val;
	if (size % val)
		nb += 1;
	current = -2147483648;
	while (i < val)
	{
		if (i == val && end != 0)
			nb = end;
		bloc = create_bloc((*a), nb, &current);
		exec_algo_hundred(bloc, a, b, nb);
		free(bloc);
		i++;
	}
	sort_b_for_end(a, b);
}
