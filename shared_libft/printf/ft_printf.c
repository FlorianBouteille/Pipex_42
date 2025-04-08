/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:48:30 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/02 11:37:34 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	toggle_types(va_list args, int type)
{
	if (type == 'c')
		return (print_char(va_arg(args, int)));
	if (type == 's')
		return (print_str(va_arg(args, char *)));
	if (type == 'i' || type == 'd')
		return (print_nbr(va_arg(args, int)));
	if (type == 'x' || type == 'X')
		return (print_hexa(va_arg(args, unsigned), type));
	if (type == 'p')
		return (print_full_adress(va_arg(args, void *)));
	if (type == 'u')
		return (print_unsigned(va_arg(args, unsigned)));
	if (type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;	
	int		final_len;
	va_list	args;
	int		i;

	len = ft_strlen((char *)str);
	final_len = len;
	va_start(args, str);
	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == '%')
		{
			final_len += toggle_types(args, str[i + 1]) - 2;
			i++;
		}
		else if (i < len)
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (final_len);
}
