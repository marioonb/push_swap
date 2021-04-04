/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelorge <mbelorge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:26:08 by mbelorge          #+#    #+#             */
/*   Updated: 2021/02/16 12:27:41 by mbelorge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_alloc_int(int size)
{
	char* res;

	res = malloc (sizeof(int) * size);
	if (!res)
		return(NULL);
	return(res);

}

char *ft_alloc_char(int size)
{
	char* res;

	res = malloc (sizeof(char) * size);
	if (!res)
		return(NULL);
	return(res);

}
