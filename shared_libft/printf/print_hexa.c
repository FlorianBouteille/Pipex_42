/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:23:20 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/02 11:54:35 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	get_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	print_hexa(unsigned int nb, char type)
{
	int	len;

	len = get_len(nb);
	if (nb >= 16)
	{
		print_hexa(nb / 16, type);
		print_hexa(nb % 16, type);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', 1);
		else
		{
			if (type == 'X')
				ft_putchar_fd(nb + 55, 1);
			if (type == 'x' || type == 'p')
				ft_putchar_fd(nb + 87, 1);
		}
	}
	return (len);
}
