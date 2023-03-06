/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:26:41 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 19:38:49 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_io_file(t_info *info)
{
	char	*infile;
	char	*outfile;

	infile = info->agv[1];
	outfile = info->agv[info->agc - 1];
	info->io_file[IN] = open(infile, O_RDONLY);
	if (info->io_file[IN] < 0)
	{
		if (errno == ENOENT)
			perror(infile);
		else
			error_exit(0, "open");
	}
	info->io_file[OUT] = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info->io_file[OUT] < 0)
		error_exit(0, "open");
}

void	get_env(char **environ, t_info *info)
{
	if (environ == NULL)
		error_exit(ERR_ENV, NULL);
	while (1)
	{
		if (*environ == NULL)
			error_exit(ERR_PATH, NULL);
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
	int		i;
	char	*tmp;
	char	*cmd_path;

	tmp = NULL;
	cmd_path = NULL;
	i = 0;
	while (info->env[i])
	{
		if (ft_strchr(info->cmd[0], '/') == NULL)
			tmp = ft_strjoin(info->env[i], "/");
		cmd_path = ft_strjoin(tmp, info->cmd[0]);
		if (errno == ENOMEM)
			error_exit(0, "malloc");
		free(tmp);
		if (!access(cmd_path, 0))
			break ;
		free(cmd_path);
		cmd_path = NULL;
		i++;
	}
	info->cmd[0] = cmd_path;
}
