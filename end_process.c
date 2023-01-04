/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:58:40 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/03 01:04:08 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free(arr);
}

void	print_error(char *error)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void	end_process(char *path, char **cmd)
{
	close(0);
	close(1);
	close(2);
	free(path);
	free_arr(cmd);
}

void	execute(char *path, char **cmd, char **envp, t_utils u)
{
	if (path != NULL && u.file[INFILE] && u.in_err == 0)
		execve(path, cmd, envp);
	if (u.in_err == 1)
	{
		end_process(path, cmd);
		exit (1);
	}
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	end_process(path, cmd);
	exit(127);
}
