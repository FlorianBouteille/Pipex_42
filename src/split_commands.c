/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:49:53 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/03 12:49:55 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_strings(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\'')
				i++;
		}
		else
		{
			while (str[i] && str[i] != ' ')
				i++;
		}
		count++;
	}
	return (count);
}

void	find_begin_indexs(int *tab, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] == '\'')
		{
			tab[j++] = i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\'')
				i++;
		}
		else
		{
			tab[j++] = i++;
			while (str[i] && str[i] != ' ')
				i++;
		}
	}
}

char	**split_command(char *str)
{
	char	**result;
	int		*begin_index;
	int		count;
	int		i;

	count = count_strings(str);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	begin_index = (int *)malloc(count * sizeof(int));
	if (!begin_index)
		return (NULL);
	find_begin_indexs(begin_index, str);
	i = 0;
	while (i < count)
	{
		result[i] = build_word(str + begin_index[i]);
		i++;
	}
	free(begin_index);
	result[i] = NULL;
	return (result);
}
