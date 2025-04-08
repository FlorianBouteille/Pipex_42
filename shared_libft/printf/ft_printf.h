/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:58:41 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/02 11:56:56 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		print_char(char c);
int		print_str(char *str);
int		print_nbr(int nb);
int		print_hexa(unsigned int nb, char type);
int		print_full_adress(void *ptr);
int		print_unsigned(unsigned int nb);

#endif
