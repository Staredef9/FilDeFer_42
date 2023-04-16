/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:57:41 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/21 16:31:19 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_negative(int n)
{
	char	*array;
	long	numero;
	int		digit_counter_negative;

	digit_counter_negative = 0;
	numero = n;
	while (numero != 0)
	{
		digit_counter_negative++;
		numero = numero / 10;
	}
	n = n * -1;
	array = malloc(((digit_counter_negative + 2) * sizeof(char)));
	if (!array)
		return (NULL);
	array[digit_counter_negative + 1] = '\0';
	while (n != 0)
	{
		array[digit_counter_negative] = (n % 10) + '0';
		n = n / 10;
		digit_counter_negative--;
	}
	array[0] = '-';
	return (array);
}

static char	*is_positive(int n)
{
	char	*array;
	long	numero;
	int		digit_counter;

	digit_counter = 0;
	numero = n;
	while (numero != 0)
	{
		digit_counter++;
		numero = numero / 10;
	}
	array = (char *)malloc((digit_counter + 1) * sizeof(char));
	if (!array)
		return (NULL);
	array[digit_counter] = '\0';
	while (n != 0)
	{
		array[digit_counter - 1] = (n % 10) + '0';
		n = n / 10;
		digit_counter--;
	}
	return (array);
}

char	*ft_itoa(int n)
{
	char	*to_return;

	if (n == -2147483648)
	{
		to_return = malloc(12 * sizeof(char));
		if (!to_return)
			return (NULL);
		ft_memcpy(to_return, "-2147483648", 12);
		return (to_return);
	}
	if (n == 0)
	{
		to_return = malloc(2);
		if (!to_return)
			return (NULL);
		to_return[0] = '0';
		to_return[1] = '\0';
		return (to_return);
	}
	else if (n < 0)
		return (is_negative(n));
	else
		return (is_positive(n));
	return (0);
}
