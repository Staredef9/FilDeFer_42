/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:31:30 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/22 12:48:39 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *c, int n)
{	
	int		i;
	char	*ptr;

	i = ft_strlen(c);
	while (i >= 0)
	{
		if (c[i] == (char)n)
		{
			ptr = (char *)c + i;
			return (ptr);
		}
		i--;
	}
	return (NULL);
}
