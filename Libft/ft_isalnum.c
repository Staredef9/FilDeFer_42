/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:56:21 by fsalvett          #+#    #+#             */
/*   Updated: 2022/10/13 13:16:35 by fsalvett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	ch;

	ch = c;
	if (ft_isalpha(ch) == 1 || ft_isdigit(ch) == 1)
		return (1);
	else
		return (0);
}
