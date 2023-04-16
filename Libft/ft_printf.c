/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:25:38 by fsalvett          #+#    #+#             */
/*   Updated: 2023/02/02 10:30:43 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char check, va_list args)
{
	int	i;

	i = 0;
	if (check == 'c')
		i = ft_char_conversion(va_arg(args, int));
	if (check == 'u')
		i = ft_unsigned_conversion(va_arg(args, unsigned int));
	if (check == 'd' || check == 'i')
		i = ft_printnbr(va_arg(args, int));
	if (check == 's')
		i = ft_string_conversion(va_arg(args, char *));
	if (check == 'x')
		i = ft_hexa_min_conversion(va_arg(args, unsigned int));
	if (check == 'X')
		i = ft_hexa_maiusc_conversion(va_arg(args, unsigned int));
	if (check == '%')
	{
		i += 1;
		write(1, "%", 1);
	}
	if (check == 'p')
		i = ft_pt_conversion(va_arg(args, void *));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		to_return;

	i = 0;
	to_return = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			to_return += 1;
		}
		else if (str[i] == '%')
		{
			to_return += ft_check(str[i + 1], args);
			i++;
		}	
		i++;
	}
	va_end(args);
	return (to_return);
}
