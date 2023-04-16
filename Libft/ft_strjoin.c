/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:05:12 by fsalvett          #+#    #+#             */
/*   Updated: 2023/03/12 10:30:52 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	string_free(char *str)
{
	free(str);
	str = NULL;
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 1;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(*str));
		str[0] = '\0';
	}
	j = ft_strlen(str) + ft_strlen(buff);
	if (!str || !buff)
		return (NULL);
	new_str = malloc((j + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	if (str)
		while (*str != '\0' && i++)
			*(new_str++) = *(str++);
	while (*buff != '\0')
		*(new_str++) = *(buff++);
	*new_str = '\0';
	return (new_str - j);
}

char	*ft_strjoin_free(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	i = 1;
	if (!str)
	{
		str = (char *)malloc(1 * sizeof(*str));
		str[0] = '\0';
	}
	j = ft_strlen(str) + ft_strlen(buff);
	if (!str || !buff)
		return (NULL);
	new_str = malloc((j + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	if (str)
		while (*str != '\0' && i++)
			*(new_str++) = *(str++);
	while (*buff != '\0')
		*(new_str++) = *(buff++);
	*new_str = '\0';
	str -= (i - 1);
	string_free(str);
	return (new_str - j);
}
