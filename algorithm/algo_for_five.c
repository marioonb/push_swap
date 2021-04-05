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

static void	insert_int(t_list **lista, t_list **lb)
{
	t_list	*a;

	a = (*lista);
	if (DEBUG == 1)
	{
		dpf(1, "A est trié !!\nInsertion du 1er element de B, recherche meill");
		dpf(1, "eur position dans A.....\nIl reste %d \n\n", ft_lstsize((*lb)));
	}
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
	int		i;
	int		nb_min;
	int		size;

	i = 0;
	if (DEBUG == 1)
	{
		dpf(1, ""TK"--------------------------------\n||  ALGORITHME POU"ST"");
		dpf(1, ""TK"R 5 NOMBRES ||\n--------------------------------"ST"\n\n");
		dpf(1, "Push sur b jusqu'a n'avoir que 3 elements dans A\n\n");
	}
	nb_min = search_min((*lista));
	size = ft_lstsize((*lista));
	while ((size-- > 3))
		execute("pb", lista, listb);
	algo_for_three(lista, listb);
	while ((*listb) != NULL && i++ < 10)
		insert_int(lista, listb);
	if (DEBUG == 1 && (*lista)->nb > nb_min)
		dpf(1, "Rotate jusqu'a ce que A soit du plus petit au plus grand\n");
	while ((*lista)->nb > nb_min)
		execute("rra", lista, listb);
	if (DEBUG == 1)
		dpf(1, "la pile b est vide... et la pile a est triée..\n\n");
}
