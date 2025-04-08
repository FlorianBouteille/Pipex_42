/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:51:31 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/21 17:01:38 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, int size)
{
	int					i;
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	i = 0;
	ptr1 = (unsigned char *)dest;
	ptr2 = (const unsigned char *)src;
	if (!src && !dest)
		return (dest);
	while (size && i < size)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dest);
}
