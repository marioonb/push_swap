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

#include "../include/checker.h"
#include "../include/all.h"

void		free_stack(t_list *list)
{
	if (list && list->next)
		free_stack(list->next);
	if (list != 0)
		free(list);
}

int			main(int ac, char **av)
{
	t_list	*lista;
	t_list	*listb;

	(void)ac;
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
	free_stack(lista);
	free_stack(listb);
	return (0);
}
