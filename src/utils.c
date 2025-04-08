/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:06:21 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/05 12:06:23 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*add_slash(char *str)
{
	char	*result;
	int		i;

	result = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i++] = '/';
	result[i] = 0;
	return (result);
}

int	is_the_same(char *str1, char *str2)
{
	int	i;

	if (ft_strlen(str1) != ft_strlen(str2))
		return (0);
	i = 0;
	while (i < ft_strlen(str1))
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	exit_usage(int mode)
{
	if (mode == 0)
	{
		ft_putstr_fd("Wrong input\n", 2);
		ft_putstr_fd("usage : infile \"cmd1\" ... \"cmdN\" outfile\n", 2);
	}
	else if (mode == 1)
	{
		ft_putstr_fd("Wrong input\n", 2);
		ft_putstr_fd("usage : here_doc LIMIT \"cmd1\" ... \"cmdN\" out\n", 2);
	}
	exit(0);
}

int	*alloc_pids_tab(int argc, char *argv[])
{
	int	size;
	int	*tab;

	if (is_the_same(argv[1], "here_doc"))
		size = argc - 4;
	else
		size = argc - 3;
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL);
	fprintf(stderr, "un tableau de taille %i a ete cree\n", size);
	return (tab);
}

void	wait_and_free_children(int j)
{
	int	i;

	i = 0;
	while (i <= j)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}
