/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/all.h"

void		algo_for_three(t_list **l, t_list **lb)
{
	t_list	*a;

	a = (*l);
	if (DEBUG == 1)
	{
		dpf(1, ""TK"--------------------------------\n||  ALGORITHME POU"ST"");
		dpf(1, ""TK"R 3 NOMBRES ||\n--------------------------------"ST"\n\n");
	}
	while (check_sort_stack(l) != 1)
	{
		a = (*l);
		if (ft_lstsize(a) < 3)
			execute("sa", l, lb);
		else if (((a->nb > a->next->nb || a->nb < a->next->nb) &&
		(a->nb < a->next->next->nb))
		|| reverse_sort(l))
			execute("sa", l, lb);
		else if (a->nb > a->next->nb && a->nb > a->next->next->nb)
			execute("ra", l, lb);
		else if (a->nb < a->next->nb && a->nb > a->next->next->nb)
			execute("rra", l, lb);
	}
}
