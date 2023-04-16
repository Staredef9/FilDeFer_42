/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:18:52 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/22 12:03:53 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t				i;
	size_t				j;
	char				*substring;

	i = 0;
	j = 0;
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	while (s[i] != '\0')
	{	
		if (i >= start && j < len)
		{
			substring[j] = s[i];
			j++;
		}
		i++;
	}
	substring[j] = '\0';
	return (substring);
}
