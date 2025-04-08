/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_commands2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:56:59 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/25 17:57:01 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*make_quoted_word(char *str)
{
	int		i;
	int		j;
	char	*word;

	i = 1;
	while (str[i] && str[i] != '\'')
		i++;
	word = malloc((i) * sizeof(char));
	if (!word)
		return (NULL);
	i = 1;
	j = 0;
	while (str[i] && str[i] != '\'')
		word[j++] = str[i++];
	word[j] = 0;
	return (word);
}

char	*make_normal_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	*build_word(char *str)
{
	if (str[0] == '\'')
		return (make_quoted_word(str));
	else
		return (make_normal_word(str));
}
