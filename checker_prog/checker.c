/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

static void	search_operation(char *buffer, t_list **lista, t_list **listb)
{
	char	**tab;

	tab = ft_split(buffer, ' ');
	while (*tab)
	{
		appli_instruct(*tab, lista, listb);
		if (g_debug_bonus == 1)
			affiche_2((*lista), (*listb));
		tab++;
	}
}

int			main(int ac, char **av)
{
	int		i;
	t_list	*lista;
	t_list	*listb;
	char	*buffer;

	(void)ac;
	i = 0;
	lista = NULL;
	listb = NULL;
	buffer = NULL;
	check_error(av);
	create_list(&lista, av);
	if (DEBUG == 1 || g_debug_bonus == 1)
		affiche_2(lista, listb);
	while (get_next_line(0, &buffer) > 0)
	{
		search_operation(buffer, &lista, &listb);
		free(buffer);
	}
	free(buffer);
	if (check_sort(lista, listb))
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
}
