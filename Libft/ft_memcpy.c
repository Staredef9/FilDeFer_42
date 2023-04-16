/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:10:03 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/13 11:11:12 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destinazione;
	const unsigned char	*fonte;
	size_t				i;

	i = 0;
	destinazione = dest;
	fonte = src;
	while (i < n)
	{
		destinazione[i] = fonte[i];
		i++;
	}	
	return ((char *)destinazione);
}
