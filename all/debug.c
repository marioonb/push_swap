/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

void	debug_util(t_list *a, t_list *b)
{
	if (DEBUG == 1)
		dpf(1, ""GR"\n----- MODE DEBUGAGE ACTIVE -----\n"ST"");
	else if (g_debug_bonus == 1)
		dpf(1, ""GR"\n----- MODE VERBOSE ACTIVE -----\n"ST"");
	dpf(1, "\n"SL"Les deux piles de depart sont :"ST"\n\n");
	affiche_2(a, b);
}
