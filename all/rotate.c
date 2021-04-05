/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

/*
** shift up all elements of stack by 1. The first element becomes
** the last one.
*/

void		rotate(t_list **list, char c)
{
	int		val;
	t_list	*new;

	if (DEBUG == 1 || g_debug_bonus == 1)
		dpf(1, "---------- ***** ROTATE_%c\n", c);
	if ((*list) != NULL)
	{
		val = pop_pile(list);
		new = ft_lstnew(val);
		ft_lstadd_back(list, new);
	}
}

/*
** call rotate for 2 stack.
*/

void		rotate_ab(t_list **lista, t_list **listb)
{
	rotate(lista, 'A');
	rotate(listb, 'B');
}
