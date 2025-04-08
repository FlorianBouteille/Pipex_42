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

int	main(int argc, char *argv[], char *envp[])
{
	int	i;

	if (argc != 5)
	{
		ft_printf("Wrong input\n");
		ft_printf("Usage : ./pipex in cmd1 cmd2 out\n");
	}
	else
	{
		if (redirect_input(argv, 0))
			exec_by_pipe(argv[2], envp);
		exec_last_command(argv, argc, envp);
		i = 0;
		while (i < 2)
		{
			waitpid(-1, NULL, 0);
			i++;
		}
	}
	return (0);
}
