/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:25:44 by fsalvett          #+#    #+#             */
/*   Updated: 2022/11/17 11:28:43 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_print_count_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_count_str(num);
	free(num);
	return (len);
}

static char	*is_upositive(unsigned int n)
{
	char				*array;
	unsigned long int	numero;
	unsigned int		digit_counter;

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

char	*ft_uitoa(unsigned int n)
{
	char	*to_return;

	if (n == 0)
	{
		to_return = malloc(2);
		if (!to_return)
			return (NULL);
		to_return[0] = '0';
		to_return[1] = '\0';
		return (to_return);
	}
	else
		return (is_upositive(n));
	return (0);
}
