/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

static void	ft_error(void)
{
	dprintf(1, "Error\n");
	exit(EXIT_FAILURE);
}

int			check_min_and_max(char *s)
{
	if (*s == '-')
	{
		if (strlen(s) < 11)
			return (1);
		if (strncmp(s, INT_MIN_C, ft_strlen(s)) > 0)
			return (0);
	}
	else
	{
		if (*s == '+')
			s++;
		if (strlen(s) < 10)
			return (1);
		if (strncmp(s, INT_MAX_C, ft_strlen(s)) > 0)
			return (0);
	}
	return (1);
}

int			check_int_type(char *s)
{
	int		d;

	d = ft_atoi(s);
	if (ft_isnumber(s) != 1)
	{
		if (DEBUG == 1)
			printf("element %s, is not an int\n", s);
		return (0);
	}
	if (!check_min_and_max(s))
	{
		if (DEBUG == 1)
			printf("element %s, not between in int intervalle\n", s);
		return (0);
	}
	return (1);
}

void		check_error(char **tab)
{
	int		i;
	int		j;

	i = 1;
	if (strcmp(tab[i], "-v") == 0)
	{
		g_debug_bonus = 1;
		i++;
	}
	while (tab[i])
	{
		if (check_int_type(tab[i]) != 1)
			ft_error();
		j = 1;
		while (j < i)
		{
			if (atoi(tab[i]) == atoi(tab[j]))
			{
				if (DEBUG == 1)
					printf("%d est en doublon\n", atoi(tab[i]));
				printf("Error");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void		appli_instruct(char *line, t_list **lista, t_list **listb)
{
	if (ft_strcmp(line, "sa") == 0)
		swap(lista, 'A');
	else if (ft_strcmp(line, "sb") == 0)
		swap(listb, 'B');
	else if (ft_strcmp(line, "ss") == 0)
		swap_ab(lista, listb);
	else if (ft_strcmp(line, "pa") == 0)
		push(lista, listb, 'A');
	else if (ft_strcmp(line, "pb") == 0)
		push(listb, lista, 'B');
	else if (ft_strcmp(line, "ra") == 0)
		rotate(lista, 'A');
	else if (ft_strcmp(line, "rb") == 0)
		rotate(listb, 'B');
	else if (ft_strcmp(line, "rr") == 0)
		rotate_ab(lista, listb);
	else if (ft_strcmp(line, "rra") == 0)
		invers_rotate(lista, 'A');
	else if (ft_strcmp(line, "rrb") == 0)
		invers_rotate(listb, 'B');
	else if (ft_strcmp(line, "rrr") == 0)
		invers_rotate_ab(lista, listb);
	else
		printf("Error\n");
}
