/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:35:35 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/21 16:27:39 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *ptr, int value, int size)
{
	int				i;
	unsigned char	*pointer;
	unsigned char	byte_value;

	pointer = ptr;
	byte_value = (unsigned char)value;
	i = 0;
	while (i < size)
	{
		pointer[i] = byte_value;
		i++;
	}
	return (ptr);
}
