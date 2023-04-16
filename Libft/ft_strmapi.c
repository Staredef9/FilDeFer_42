/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:53:40 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/19 17:53:43 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*to_return;
	int		i;

	i = 0;
	to_return = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!to_return)
		return (NULL);
	while (s[i] != '\0')
	{
		to_return[i] = (*f)(i, s[i]);
		i++;
	}
	to_return[i] = '\0';
	return (to_return);
}
