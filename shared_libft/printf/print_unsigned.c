/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:14:37 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/02 11:56:06 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	put_unsigned(unsigned int nb)
{
	if (nb >= 10)
		put_unsigned(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
}

static int	get_len(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

int	print_unsigned(unsigned int nb)
{
	put_unsigned(nb);
	return (get_len(nb));
}
