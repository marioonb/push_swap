/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

/*
** shift down all elements of stack by 1. The last element
** becomes the first one.
*/

void		invers_rotate(t_list **list, char c)
{
	int		val;
	t_list	*new;

	if (DEBUG == 1 || g_debug_bonus == 1)
		dpf(1, "---------- ***** REVERSE_ROTATE_%c\n", c);
	new = (*list);
	while (new && new->next && new->next->next)
		new = new->next;
	if (new && new->next)
	{
		val = new->next->nb;
		free(new->next);
		new->next = NULL;
		push_pile(list, val);
	}
}

/*
** call invers_rotate for 2 stack.
*/

void		invers_rotate_ab(t_list **lista, t_list **listb)
{
	invers_rotate(lista, 'A');
	invers_rotate(listb, 'B');
}
