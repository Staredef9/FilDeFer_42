/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:07:30 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/13 15:04:23 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*primo;
	const unsigned char	*secondo;
	size_t				i;

	primo = s1;
	secondo = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (primo[i] != secondo[i])
			return (primo[i] - secondo[i]);
		i++;
	}
	return (0);
}
