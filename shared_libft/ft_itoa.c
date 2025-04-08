/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:00:28 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/21 16:36:02 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	long int	nb;

	nb = n;
	len = get_len(nb);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (nb == 0)
		result[0] = '0';
	result[len] = 0;
	if (nb < 0)
	{
		nb = -nb;
		result[0] = '-';
	}
	while (nb > 0)
	{
		result[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (result);
}
