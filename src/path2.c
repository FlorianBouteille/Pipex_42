/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:06:32 by fbouteil          #+#    #+#             */
/*   Updated: 2025/02/24 12:06:35 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_absolute_path(char *str)
{
	if (access(str, F_OK) == 0)
	{
		if (access(str, X_OK) == 0)
			return (1);
	}
	return (0);
}

char	*try_with_usrbin(char *str)
{
	char	*result;

	result = ft_strjoin("/usr/bin/", str);
	if (access(result, F_OK) == 0 && access(result, X_OK) == 0)
		return (result);
	return (free(result), NULL);
}

char	*look_for_path(char *str, char *envp[])
{
	if (!str || str[0] == '0')
		return (NULL);
	if (is_absolute_path(str))
		return (ft_strdup(str));
	else if (is_valid_env(envp))
		return (get_right_path(str, envp));
	else
		return (try_with_usrbin(str));
}
