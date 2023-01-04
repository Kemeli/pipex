/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:56:04 by kdaiane-          #+#    #+#             */
/*   Updated: 2023/01/03 00:42:42 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	last_process(char **envp, char **argv, t_utils u)
{
	char	**cmd;
	char	*path;

	u.file[OUTFILE] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (u.file[OUTFILE] == -1)
	{
		close(u.fd[1]);
		close(u.fd[0]);
		close(u.file[OUTFILE]);
		print_error("outfile : Permission denied");
	}
	dup2(u.fd[0], STDIN_FILENO);
	dup2(u.file[OUTFILE], STDOUT_FILENO);
	close(u.fd[1]);
	close(u.fd[0]);
	close(u.file[OUTFILE]);
	if (u.in_err == 0)
		close (u.file[INFILE]);
	cmd = handle_quotes(argv[3]);
	path = get_path(envp, cmd[0]);
	u.in_err = 0;
	execute(path, cmd, envp, u);
}

static void	first_process(char **envp, char **argv, t_utils u)
{
	char	**cmd;
	char	*path;

	dup2 (u.fd[1], STDOUT_FILENO);
	if (u.in_err != 1)
	{
		dup2 (u.file[INFILE], STDIN_FILENO);
		close (u.file[INFILE]);
	}
	close (u.fd[1]);
	close (u.fd[0]);
	cmd = handle_quotes(argv[2]);
	path = get_path(envp, cmd[0]);
	execute(path, cmd, envp, u);
}

void	call_processes(t_utils u, char *argv[], char **envp)
{
	u.pipe_ret = pipe(u.fd);
	if (u.pipe_ret == -1)
		print_error("error pipe()");
	u.pid = fork();
	if (u.pid == -1)
		print_error("error fork()");
	if (u.pid == 0)
		first_process(envp, argv, u);
	u.pid2 = fork();
	if (u.pid2 == -1)
		print_error("error fork()");
	if (u.pid2 == 0)
		last_process(envp, argv, u);
	close (u.fd[1]);
	close (u.fd[0]);
	if (u.in_err == 0)
		close (u.file[INFILE]);
	waitpid(u.pid2, &u.status, 0);
	if (WIFEXITED(u.status))
		u.status = WEXITSTATUS(u.status);
	exit(u.status);
}
