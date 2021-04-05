/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

/*
** take the first element at the top of first pile and put it
** at the top ofsecond pile. Do nothing if the second pile is empty.
*/

void		push(t_list **list1, t_list **list2, char c)
{
	int nb;

	if (DEBUG == 1 || g_debug_bonus == 1)
		dpf(1, "---------- ***** PUSH_%c\n", c);
	if (*list2)
	{
		nb = pop_pile(list2);
		push_pile(list1, nb);
	}
}
