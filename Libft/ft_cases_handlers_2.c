/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_handlers_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:13:21 by fsalvett          #+#    #+#             */
/*   Updated: 2022/11/17 11:14:29 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_pt_conversion(void *ptr)
{
	uintptr_t	pconv;
	int			to_return;

	pconv = (uintptr_t)ptr ;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		to_return = 5;
		return (to_return);
	}
	else
	{
		to_return = 2;
		write(1, "0x", 2);
		to_return += ft_hexa_min_conversion(pconv);
	}
	return (to_return);
}

unsigned int	ft_unsigned_conversion(unsigned int i)
{
	char				*unum;
	unsigned int		to_return;

	to_return = 0;
	unum = ft_uitoa(i);
	to_return = ft_print_count_str(unum);
	free(unum);
	return (to_return);
}

int	ft_percent_conversion(char per)
{
	if (per == '%')
		write (1, "%", 1);
	return (1);
}

int	ft_char_conversion(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_string_conversion(char *str)
{
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}
}
