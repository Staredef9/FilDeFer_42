/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:13:01 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/14 12:33:36 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t				i;
	char				*fillarea;
	unsigned char		ch;

	ch = c;
	fillarea = s;
	i = 0;
	while (i < n)
	{
		fillarea[i] = ch;
		i++;
	}
	return (fillarea);
}
