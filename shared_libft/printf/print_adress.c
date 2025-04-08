/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:37:46 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/02 11:53:00 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	get_len(unsigned long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

static void	print_adress(unsigned long nb)
{
	if (nb >= 16)
	{
		print_adress(nb / 16);
		print_adress(nb % 16);
	}
	else
	{
		if (nb < 10)
			ft_putchar_fd(nb + '0', 1);
		else
			ft_putchar_fd(nb + 87, 1);
	}
}

int	print_full_adress(void *ptr)
{
	unsigned long	adress;

	adress = (unsigned long)ptr;
	if (adress == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	print_adress(adress);
	return (get_len(adress) + 2);
}
