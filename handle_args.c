/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 19:06:44 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/12/29 02:25:45 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **envp, char *cmd)
{
	int		i;
	t_path	p;

	p.path = NULL;
	i = 0;
	while (ft_strncmp("PATH=", envp[i], 5))
		i++;
	p.temp = ft_split(envp[i] + 5, ':');
	p.slash_cmd = ft_strjoin("/", cmd);
	i = 0;
	while (p.temp[i])
	{
		p.poss_path = ft_strjoin(p.temp[i], p.slash_cmd);
		if (access (p.poss_path, F_OK) == 0)
		{
			p.path = p.poss_path;
			break ;
		}
		i++;
		free (p.poss_path);
	}
	free (p.slash_cmd);
	free_arr(p.temp);
	return (p.path);
}

char	**handle_quotes(char *cmd)
{
	int		i;
	char	*temp;
	char	**cmd_arg;
	int		quotes;

	i = 0;
	quotes = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			quotes = 1;
			ft_memmove (&cmd[i], &cmd[i + 1], ft_strlen(&cmd[i]) + 1);
		}
		else if (cmd[i] == ' ' && !quotes)
			cmd[i] = SPACE_NULL;
		i++;
	}
	cmd_arg = ft_split(cmd, SPACE_NULL);
	if (!cmd_arg[0])
		return (cmd_arg);
	temp = cmd_arg[1];
	cmd_arg[1] = ft_strtrim(temp, "'");
	free(temp);
	return (cmd_arg);
}
