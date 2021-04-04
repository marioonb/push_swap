/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limked_list_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/04/04 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/all.h"

void		ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

t_list		*ft_lstnew(int val)
{
	t_list	*resultat;

	resultat = (t_list*)malloc(sizeof(t_list));
	if (!resultat)
		return (0);
	resultat->nb = val;
	resultat->next = NULL;
	return (resultat);
}

int			pop_pile(t_list **list)
{
	int		val;
	t_list	*tmp;

	if (!*list)
		return (-1);
	tmp = (*list)->next;
	val = (*list)->nb;
	free(*list);
	*list = tmp;
	return (val);
}

void		ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void		push_pile(t_list **list, int val)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		exit(EXIT_FAILURE);
	element->nb = val;
	element->next = *list;
	*list = element;
}
