/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/all.h"

static void	search_operation(char *buffer, t_list **lista, t_list **listb)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(buffer, ' ');
	while (tab[i])
	{
		appli_instruct(tab[i], lista, listb);
		if (g_debug_bonus == 1 || DEBUG == 1)
			affiche_2((*lista), (*listb));
		i++;
	}
	free_tab_char(tab);
}

void		read_instruct(t_list **a, t_list **b)
{
	char	*buffer;

	buffer = NULL;
	while (get_next_line(0, &buffer) > 0)
	{
		search_operation(buffer, a, b);
		free(buffer);
	}
	free(buffer);
}
