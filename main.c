/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:52:51 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/12/26 17:52:51 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	t_utils	u;

	u.in_err = 0;
	u.file[INFILE] = open(argv[1], O_RDONLY, 0444);
	if (u.file[INFILE] == -1)
	{
		u.in_err = 1;
		ft_putstr_fd("bash : ", 2);
		perror(argv[1]);
	}
	u.status = 0;
	if (argc == 5)
		call_processes(u, argv, envp);
	else
	{
		ft_putstr_fd("pipex : invalid number of arguments\nexample: ", 2);
		ft_putstr_fd("./pipex <infile> <cmd1> <cmd2> <outfile>", 2);
		exit(1);
	}
}
