/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:30:25 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/22 12:28:02 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t				i;
	size_t				j;

	i = 0;
	j = 0;
	if (!haystack)
		return (NULL);
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (i < n && haystack[i] != '\0')
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] != '\0' && j + i < n)
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}	
