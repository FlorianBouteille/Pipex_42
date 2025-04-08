/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:57:46 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/29 17:08:21 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	print_nbr(int nb)
{
	int	nb_len;

	nb_len = 0;
	if (nb == 0)
		nb_len++;
	if (nb < 0)
		nb_len++;
	ft_putnbr_fd(nb, 1);
	while (nb != 0)
	{
		nb /= 10;
		nb_len++;
	}
	return (nb_len);
}
