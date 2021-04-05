/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/all.h"

int			reverse_sort(t_list **list)
{
	t_list	*a;

	a = (*list);
	while (a && a->next)
	{
		if (a->next->nb > a->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

int			check_sort_stack(t_list **lista)
{
	t_list	*a;

	a = (*lista);
	while (a && a->next)
	{
		if (a->next->nb < a->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

void		execute(char *s, t_list **a, t_list **b)
{
	dpf(1, "%s\n", s);
	appli_instruct(s, a, b);
	if (DEBUG == 1 || g_debug_bonus == 1)
	{
		affiche_2((*a), (*b));
	}
}

void		find_type_sort(t_list **lista, t_list **listb)
{
	int		size;

	size = ft_lstsize(*lista);
	if (DEBUG == 1 && size > 5)
	{
		dpf(1, ""TK"--------------------------------\n||   ALGO POUR GR"ST"");
		dpf(1, ""TK"ANDE LISTE   ||\n--------------------------------"ST"\n\n");
		dpf(1, ""IT"division des elements en 5 a 11 blocs"ST"\n\n");
	}
	if (size <= 3)
		algo_for_three(lista, listb);
	else if (size <= 5)
		algo_for_five(lista, listb);
	else if (size <= 100)
		algo_for_hundred(lista, listb, size, 5);
	else if (size > 100)
		algo_for_hundred(lista, listb, size, 11);
	if (DEBUG == 1 || g_debug_bonus == 1)
	{
		dpf(1, ""GR"YOUPPI !! ---->"ST"");
		affiche_list((*lista));
		dpf(1, "\n\n");
	}
}

int			main(int ac, char **av)
{
	t_list	*lista;
	t_list	*listb;

	(void)ac;
	if (!av[1])
		return (0);
	lista = NULL;
	listb = NULL;
	check_error(av);
	create_list(&lista, av);
	if (DEBUG == 1 || g_debug_bonus == 1)
		debug_util(lista, listb);
	if (!check_sort(lista, listb))
		find_type_sort(&lista, &listb);
	else if (DEBUG == 1 || g_debug_bonus == 1)
	{
		dpf(1, ""PK"La liste est déja triée ---> "ST"");
		affiche_list((lista));
	}
	return (0);
}
