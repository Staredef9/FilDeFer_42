/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_handlers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:39:36 by fsalvett          #+#    #+#             */
/*   Updated: 2022/11/17 11:11:45 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_counter(uintptr_t i)
{
	int	counter;

	counter = 0;
	if (i == 0)
		counter = 1;
	while (i != 0)
	{
		i = i / 16;
		counter ++;
	}
	return (counter);
}

int	hex_internal_conv_min(uintptr_t i, char *array, int max_a)
{
	int		ft_remainder;
	int		counter;

	ft_remainder = 0;
	counter = 0;
	while (i != 0)
	{
		ft_remainder = i % 16;
		if (ft_remainder >= 10 && ft_remainder <= 15)
			array[max_a - counter] = ft_remainder + 87;
		else if (ft_remainder < 10)
			array[max_a - counter] = ft_remainder + 48;
		i /= 16;
		counter += 1;
	}
	return (counter);
}

int	hex_internal_conv_ma(uintptr_t i, char *array, int max_array)
{
	int		ft_remainder;
	int		counter;

	ft_remainder = 0;
	counter = 0;
	while (i != 0)
	{
		ft_remainder = i % 16;
		if (ft_remainder >= 10 && ft_remainder <= 15)
			array[max_array - counter] = ft_remainder + 55;
		else if (ft_remainder < 10)
			array[max_array - counter] = ft_remainder + 48;
		i /= 16;
		counter += 1;
	}
	return (counter);
}

unsigned int	ft_hexa_min_conversion(uintptr_t i)
{
	char	*array;
	int		counter;
	int		max_array;

	max_array = hex_counter(i);
	array = malloc((max_array + 1) * sizeof(char));
	array[max_array] = '\0';
	counter = 0;
	max_array -= 1;
	if (i == 0)
	{
		array[max_array] = '0';
		counter = 1;
	}
	if (i > 0)
		counter = hex_internal_conv_min(i, array, max_array);
	ft_putstr(array);
	free(array);
	return (counter);
}

unsigned int	ft_hexa_maiusc_conversion(uintptr_t i)
{
	char	*array;
	int		counter;
	int		max_array;

	max_array = hex_counter(i);
	array = malloc((max_array + 1) * sizeof(char));
	array[max_array] = '\0';
	max_array -= 1;
	counter = 0;
	if (i == 0)
	{
		array[max_array] = '0';
		counter = 1;
	}
	if (i > 0)
		counter = hex_internal_conv_ma(i, array, max_array);
	ft_putstr(array);
	free(array);
	return (counter);
}
