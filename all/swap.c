/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

/*
** swap the first 2 elements at the top of stack.
** Do nothing if there is only one or no elements).
*/

void	swap(t_list **list, char c)
{
	int	temp;

	if (DEBUG == 1 || g_debug_bonus == 1)
		dpf(1, "---------- ***** SWAP_%c\n", c);
	if (*list != NULL && (*list)->next != NULL)
	{
		temp = (*list)->nb;
		(*list)->nb = (*list)->next->nb;
		(*list)->next->nb = temp;
	}
}

/*
**	call swap for 2 stack.
*/

void	swap_ab(t_list **lista, t_list **listb)
{
	swap(lista, 'A');
	swap(listb, 'B');
}
