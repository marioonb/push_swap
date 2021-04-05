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

static int	*create_bloc(t_list *list, int nb, int *current, int debug)
{
	int		*bloc;
	int		i;

	if (DEBUG == 1)
	{
		dpf(1, ""PK"*************** Creation du bloc %d "ST"\n", debug + 1);
		dpf(1, ""IT"contient les valeurs minimuns a rechercher"ST"\n");
	}
	bloc = malloc(sizeof(int) * nb);
	i = 0;
	while (i < nb)
	{
		bloc[i] = search_next_min(list, *current);
		*current = bloc[i];
		i++;
	}
	if (DEBUG == 1)
	{
		dpf(1, "Les elements a chercher sont actuellement : ");
		ft_read_tab_int(bloc, nb);
	}
	return (bloc);
}

static void	ft_debug_hundred(int pos, int pos2)
{
	if (pos - 1 > pos2 && pos2 != -1)
	{
		dpf(1, "C'est celui de la queue qui existe et ui demande ");
		dpf(1, "le moins d'actions\nSa position est %d\nNou", pos2);
		dpf(1, "s allons donc faire "GR"%d rotation(s)"ST" a droite,\n", pos2);
	}
	else
	{
		dpf(1, "C'est celui de la tete qui existe et qui demande ");
		dpf(1, "le moins d'actions\nSa position est %d\nNous ", pos - 1);
		dpf(1, "allons donc faire "GR"%d rotation(s)"ST" a gauche\n", pos - 1);
	}
	dpf(1, "puis push sur la pile b\n");
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
			ft_debug_hundred(head, queue);
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
	while (i < val && (*a))
	{
		if (i == val - 1 && size % val != 0)
			nb = size - (i * nb);
		bloc = create_bloc((*a), nb, &current, i);
		exec_algo_hundred(bloc, a, b, nb);
		free(bloc);
		i++;
	}
	if (DEBUG == 1)
	{
		dpf(1, ""TK"--------------------------------\n||          TRI DE"ST"");
		dpf(1, ""TK" B          ||\n--------------------------------"ST"\n\n");
	}
	sort_b_for_end(a, b);
}
