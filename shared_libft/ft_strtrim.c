/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:37:37 by fbouteil          #+#    #+#             */
/*   Updated: 2024/11/21 16:32:43 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(char c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_size(const char *str, const char *set)
{
	size_t	size;
	int		i;
	int		j;

	i = 0;
	size = ft_strlen(str);
	j = size - 1;
	while (j >= 0 && is_inset(str[j], set))
	{
		j--;
		size--;
	}
	while (str[i] && is_inset(str[i], set) && size)
	{
		size--;
		i++;
	}
	return (size);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*result;
	size_t	size;
	size_t	i;
	size_t	j;

	size = get_size(s1, set);
	result = malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[size] = 0;
	i = 0;
	j = 0;
	while (s1[i] && is_inset(s1[i], set))
		i++;
	while (j < size)
	{
		result[j] = s1[i + j];
		j++;
	}
	return (result);
}
