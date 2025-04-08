/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 12:34:12 by fbouteil          #+#    #+#             */
/*   Updated: 2024/12/16 12:42:41 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_free(char *buffer, char *str)
{
	char	*result;

	result = ft_strjoin(buffer, str);
	if (!result)
		return (NULL);
	free(buffer);
	return (result);
}

char	*fill_buffer(char *buffer, int fd)
{
	char	*temp;
	int		bytes_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	if (!buffer)
		buffer = ft_calloc(1, 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(temp), NULL);
		temp[bytes_read] = 0;
		buffer = join_and_free(buffer, temp);
		if (check_for_ln(buffer))
			break ;
	}
	if (*buffer == 0)
		return (free(temp), free(buffer), NULL);
	return (free(temp), buffer);
}

char	*build_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	line = ft_calloc((i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*clean_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] && buffer[i] == '\n')
		i++;
	if (ft_strlen(buffer) - i == 0)
		return (free(buffer), NULL);
	new_buffer = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!new_buffer)
		return (NULL);
	j = 0;
	while (buffer[i + j])
	{
		new_buffer[j] = buffer[i + j];
		j++;
	}
	new_buffer[j] = 0;
	return (free(buffer), new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	buffer = fill_buffer(buffer, fd);
	line = build_line(buffer);
	if (!line || *line == 0)
		return (free(buffer), NULL);
	buffer = clean_buffer(buffer);
	return (line);
}
