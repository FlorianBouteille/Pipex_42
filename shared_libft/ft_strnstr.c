/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:50:41 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/21 16:32:12 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_of_little;

	i = 0;
	j = 0;
	size_of_little = (size_t)ft_strlen(little);
	if (little[0] == 0)
		return ((char *)big);
	while (i < size && big[i])
	{
		while (i + j < size && big[i + j] == little[j])
		{
			if (j == size_of_little - 1)
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
