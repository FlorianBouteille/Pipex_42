/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:34:40 by fbouteil          #+#    #+#             */
/*   Updated: 2025/01/27 13:34:43 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int argc, char *argv[], char *envp[])
{
	int	i;
	int	j;

	j = 0;
	i = 2 + is_the_same(argv[1], "here_doc");
	if (is_the_same(argv[1], "here_doc"))
	{
		if (argc < 6)
			exit_usage(1);
		if (!redirect_input(argv, 1))
			i++;
	}
	else if (!redirect_input(argv, 0))
		i++;
	while (i < argc - 2)
	{
		exec_by_pipe(argv[i++], envp);
		j++;
	}
	exec_last_command(argv, argc, envp);
	j++;
	wait_and_free_children(j);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 5)
	{
		ft_printf("Wrong input\n");
		ft_printf("Usage : ./pipex in cmd1 ... cmdN out\n");
		return (1);
	}
	if (argc >= 5)
		pipex(argc, argv, envp);
	return (0);
}
