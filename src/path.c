/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:08:37 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/24 13:56:08 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_valid_env(char *envp[])
{
	int	i;

	if (!envp || !envp[0])
		return (0);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

char	*get_right_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path_plus_backslash;
	char	*path_to_test;

	paths = list_paths(envp);
	i = 0;
	while (paths[i])
	{
		path_plus_backslash = add_slash(paths[i]);
		path_to_test = ft_strjoin(path_plus_backslash, cmd);
		free(path_plus_backslash);
		if (access(path_to_test, F_OK) == 0)
		{
			if (access(path_to_test, X_OK) == 0)
				return (free_tab(paths), path_to_test);
			free_tab(paths);
			free(path_to_test);
			return (NULL);
		}
		free(path_to_test);
		i++;
	}
	free_tab(paths);
	return (NULL);
}

char	**list_paths(char *envp[])
{
	char	**paths;
	char	*paths_to_parse;

	paths_to_parse = get_path(envp);
	if (!paths_to_parse)
		return (NULL);
	paths = ft_split(paths_to_parse, ':');
	if (!paths)
		return (NULL);
	free(paths_to_parse);
	return (paths);
}

char	*clean_path(char *str)
{
	int		len;
	int		i;
	char	*path_cleaned;

	len = ft_strlen(str) - 5;
	path_cleaned = (char *)malloc((len + 1) * sizeof(char));
	if (!path_cleaned)
		return (NULL);
	i = 0;
	while (i < len)
	{
		path_cleaned[i] = str[i + 5];
		i++;
	}
	path_cleaned[i] = 0;
	return (path_cleaned);
}

char	*get_path(char *envp[])
{
	char	*path_variable;
	char	*cleaned_path;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	path_variable = ft_strdup(envp[i]);
	cleaned_path = clean_path(path_variable);
	free(path_variable);
	return (cleaned_path);
}
