/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:26:41 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/09 05:33:42 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_io_file(char *filename, int *io_file, bool is_in)
{
	if (is_in)
		*io_file = open(filename, O_RDONLY);
	else
		*io_file = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (*io_file < 0)
	{
		if (errno == ENOENT)
			error_exit(ERR_PATH, filename);
		else
			error_exit(0, "open");
	}
}

void	get_env(char **environ, t_info *info)
{
	if (environ == NULL)
		error_exit(ERR_ENV, NULL);
	while (1)
	{
		if (*environ == NULL)
			error_exit(ERR_PATH, info->cmd[0]);
		if (!ft_strncmp("PATH=", *environ, 5))
			break ;
		environ++;
	}
	info->env = ft_split(*environ + 5, ':');
	if (errno == ENOMEM)
		error_exit(0, "malloc");
}

void	get_cmd_path(t_info *info)
{
	char	*tmp;
	char	*cmd_path;

	if (*info->cmd == NULL || **info->cmd == '\0')
		error_exit(ERR_CMD, NULL);
	tmp = NULL;
	cmd_path = NULL;
	while (*info->env)
	{
		if (ft_strchr(*info->cmd, '/') == NULL)
			tmp = ft_strjoin(*info->env, "/");
		cmd_path = ft_strjoin(tmp, *info->cmd);
		if (errno == ENOMEM)
			error_exit(0, "malloc");
		free(tmp);
		if (!access(cmd_path, 0))
			break ;
		free(cmd_path);
		cmd_path = NULL;
		info->env++;
	}
	if (cmd_path == NULL)
		error_exit(ERR_CMD, *info->cmd);
	*info->cmd = cmd_path;
}
