/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:23:41 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/14 17:03:22 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*newstring;
	int		i;
	int		len;

	len = ft_strlen(s);
	i = 0;
	newstring = (char *)malloc(sizeof(char) * (len + 1));
	if (newstring == NULL)
		return (NULL);
	while (i < len)
	{
		newstring[i] = s[i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
