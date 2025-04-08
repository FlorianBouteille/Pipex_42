/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:27:33 by fbouteil          #+#    #+#             */
/*   Updated: 2025/01/30 12:27:35 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_input(char *argv[], int here_doc)
{
	int	fd;
	int	dup;

	if (here_doc == 1)
		return (get_here_doc(argv), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_putstr_fd("Failed to open infile\n", 2);
		fd = open("/dev/null", O_RDONLY);
		if (dup2(fd, STDIN_FILENO) < 0)
			exit(0);
		close(fd);
		return (0);
	}
	dup = dup2(fd, STDIN_FILENO);
	if (dup < 0)
	{
		close(fd);
		exit(0);
	}
	close(fd);
	return (1);
}

int	redirect_output(char *file, int here_doc)
{
	int	fd;

	if (here_doc == 0)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("Failed to access or create file\n", 2);
		fd = open("/dev/null", O_RDONLY);
		if (dup2(fd, STDIN_FILENO) < 0)
			exit(0);
		close(fd);
		return (0);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("dup2 FAILED spectacularly\n", 2);
		close(fd);
		exit(0);
	}
	close(fd);
	return (1);
}

void	get_here_doc(char *argv[])
{
	int		pipe_fd[2];
	int		pid;

	if (pipe(pipe_fd) == -1)
		exit (0);
	pid = fork();
	if (pid == -1)
		exit (0);
	if (!pid)
	{
		close(pipe_fd[0]);
		read_input(pipe_fd, argv);
	}
	else
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
			exit(0);
		close(pipe_fd[0]);
		waitpid(pid, NULL, 0);
	}
}

int	is_limiter(char *line, char *limiter)
{
	int	i;

	i = 0;
	if (ft_strlen(line) - 1 != ft_strlen(limiter))
		return (0);
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != limiter[i])
			return (0);
		i++;
	}
	return (1);
}

void	read_input(int *pipe_fd, char *argv[])
{
	char	*line;

	while (1)
	{
		ft_putstr_fd(">", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (is_limiter(line, argv[2]))
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	close(pipe_fd[1]);
	exit (0);
}
