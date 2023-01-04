/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:12:38 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/12/26 19:12:38 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define SPACE_NULL 1
# define INFILE 0
# define OUTFILE 1

typedef struct s_utils
{
	int		file[2];
	int		pipe_ret;
	int		status;
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];
	int		in_err;
}	t_utils;

typedef struct s_path
{
	char	*slash_cmd;
	char	**temp;
	char	*poss_path;
	char	*path;
}	t_path;

void	call_processes(t_utils u, char *argv[], char **envp);
void	free_arr(char **arr);
void	print_error(char *error);
void	execute(char *path, char **cmd, char **envp, t_utils u);
char	**handle_quotes(char *cmd);
char	*get_path(char **envp, char *cmd);

#endif