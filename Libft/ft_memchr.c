/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:06:58 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/14 14:37:56 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*da_controllare;
	const unsigned char	*return_value;
	unsigned char		flag;
	size_t				i;

	da_controllare = s;
	flag = c;
	i = 0;
	while (i < n)
	{
		if (da_controllare[i] == flag)
		{
			return_value = da_controllare + i;
			return ((void *)return_value);
		}
		i++;
	}
	return (NULL);
}
