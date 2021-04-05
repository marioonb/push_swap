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
		if (g_debug_bonus == 1 || DEBUG == 1)
			affiche_2((*lista), (*listb));
		tab++;
	}
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

int			main(int ac, char **av)
{
	int		i;
	t_list	*lista;
	t_list	*listb;

	(void)ac;
	i = 0;
	lista = NULL;
	listb = NULL;
	if (!av[1])
		return (0);
	check_error(av);
	if (DEBUG == 1)
		dpf(1, ""GR"\n----- MODE DEBUGAGE ACTIVE -----\n"ST"");
	else if (g_debug_bonus == 1)
		dpf(1, ""GR"\n----- MODE VERBOSE ACTIVE -----\n"ST"");
	create_list(&lista, av);
	if (DEBUG == 1 || g_debug_bonus == 1)
		affiche_2(lista, listb);
	read_instruct(&lista, &listb);
	if (check_sort(lista, listb))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
