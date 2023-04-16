/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:21:18 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/14 12:58:54 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	integer;
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	integer = 0;
	while (nptr[i] == 32 || (nptr[i] <= 13 && nptr[i] >= 9))
		i++;
	if (nptr[i] == '-' && (ft_isdigit(nptr[i + 1]) == 1))
	{	
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+' && (ft_isdigit(nptr[i + 1]) == 1))
	{
		sign = 1;
		i++;
	}
	while ((ft_isdigit(nptr[i]) == 1))
	{
		integer = (integer * 10) + (nptr[i] - '0');
		i++;
	}
	return (integer * sign);
}
