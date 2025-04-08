/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:27:35 by fbouteil          #+#    #+#             */
/*   Updated: 2025/01/29 14:27:38 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_error(char **cmd, char *path)
{
	ft_putstr_fd("/!\\ Command ", 2);
	if (cmd && cmd[0])
	{
		ft_putstr_fd(cmd[0], 2);
		ft_putstr_fd(" ", 2);
	}
	ft_putstr_fd("not found /!\\\n", 2);
	free_tab(cmd);
	free(path);
	exit(0);
}

void	exec_command(char *cmd_arg, char *envp[])
{
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = split_command(cmd_arg);
	if (cmd != NULL)
		path = look_for_path(cmd[0], envp);
	if (path == NULL)
		exec_error(cmd, path);
	if (execve(path, cmd, envp) == -1)
		exec_error(cmd, path);
}

int	exec_last_command(char *argv[], int argc, char *envp[])
{
	int	pid;
	int	here_doc;

	here_doc = is_the_same(argv[1], "here_doc");
	if (!redirect_output(argv[argc - 1], here_doc))
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		exec_command(argv[argc - 2], envp);
	return (pid);
}

int	exec_by_pipe(char *cmd_arg, char *envp[])
{
	int	pipe_fd[2];
	int	pid;

	if (pipe(pipe_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
			return (0);
		close(pipe_fd[1]);
		exec_command(cmd_arg, envp);
	}
	else
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
			return (0);
		close(pipe_fd[0]);
		return (pid);
	}
	return (0);
}
