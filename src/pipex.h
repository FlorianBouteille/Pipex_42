/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouteil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:35:24 by fbouteil          #+#    #+#             */
/*   Updated: 2025/01/27 13:35:26 by fbouteil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../shared_libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

void	free_tab(char **tab);
char	**split_command(char *str);
char	*get_path(char *envp[]);
char	*clean_path(char *str);
char	**list_paths(char *envp[]);
int		has_valid_path(char *cmd, char **paths);
char	*get_right_path(char *cmd, char **envp);
int		is_absolute_path(char *str);
char	*look_for_path(char *str, char *envp[]);
int		is_valid_env(char *envp[]);
int		redirect_input(char *argv[], int here_doc);
int		redirect_output(char *file, int here_doc);
void	get_here_doc(char *argv[]);
void	read_input(int *pipe_fd, char *argv[]);
void	exec_command(char *cmd_arg, char *envp[]);
int		exec_by_pipe(char *cmd_arg, char *envp[]);
int		exec_last_command(char *argv[], int argc, char *envp[]);
int		*alloc_pids_tab(int argc, char *argv[]);
int		exit_usage(int mode);
void	wait_and_free_children(int j);
char	*add_slash(char *str);
int		is_the_same(char *str1, char *str2);
char	**split_command(char *str);
char	*build_word(char *str);
char	*make_normal_word(char *str);
char	*make_quoted_word(char *str);
void	find_begin_indexs(int *tab, char *str);
int		count_strings(char *str);

#endif
