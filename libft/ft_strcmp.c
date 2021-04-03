/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:24:24 by mbelorge          #+#    #+#             */
/*   Updated: 2020/12/03 12:57:15 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *name, char *value)
{
	if (ft_strlen(name) != ft_strlen(value))
		return (-1);
	return (ft_strncmp(name, value, ft_strlen(name)));
}
