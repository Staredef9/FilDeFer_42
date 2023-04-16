/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:40:40 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/14 10:34:12 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*pointer;
	size_t				byte_size;

	byte_size = nmemb * size;
	pointer = malloc(byte_size);
	if (pointer != NULL)
	{
		ft_memset(pointer, 0, byte_size);
	}
	else
		return (NULL);
	return (pointer);
}
