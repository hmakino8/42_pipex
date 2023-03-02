/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:26:41 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/01 16:05:36 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	heredoc_to_fd(char *limiter, t_info *info);

void	get_files(int argc, char **argv, t_info *info)
{
	char	*infile;
	char	*outfile;
	char	*limiter;

	infile = argv[1];
	outfile = argv[argc - 1];
	limiter = argv[2];
	if (info->heredoc)
	{
		info->io_file[0] = heredoc_to_fd(limiter, info);
		info->io_file[1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (info->io_file[1] < 0)
			error_exit(0, "open", info);
		return ;
	}
	info->io_file[0] = open(infile, O_RDONLY);
	if (info->io_file[0] < 0)
	{
		if (errno == ENOENT)
			error_exit(0, infile, info);
		error_exit(0, "open", info);
	}
	info->io_file[1] = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info->io_file[1] < 0)
		error_exit(0, "open", info);
}

void	get_paths(t_info *info)
{
	extern char	**environ;
	char		**env;

	env = environ;
	if (env == NULL)
		error_exit(ERR_ENV, NULL, info);
	while (1)
	{
		if (*env == NULL)
			error_exit(ERR_PATH, NULL, info);
		if (!ft_strncmp("PATH=", *env, 5))
			break ;
		env++;
	}
	info->env = ft_split(*env + 5, ':');
	if (errno == ENOMEM)
		error_exit(0, "malloc", info);
}

void	get_cmd(char *cmd, t_info *info)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (info->env[i])
	{
		if (ft_strchr(cmd, '/') == NULL)
		{
			tmp = ft_strjoin(info->env[i], "/");
			if (errno == ENOMEM)
				error_exit(0, "malloc", info);
		}
		info->fullpath = ft_strjoin(tmp, cmd);
		free(tmp);
		tmp = NULL;
		if (errno == ENOMEM)
			error_exit(0, "malloc", info);
		if (!access(info->fullpath, 0))
			return ;
		free(info->fullpath);
		info->fullpath = NULL;
		i++;
	}
}

static int	heredoc_to_fd(char *limiter, t_info *info)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) < 0)
		error_exit(0, "pipe", info);
	while (1)
	{
		line = ft_readline("heredoc> ");
		if (line == NULL || !ft_strcmp(line, limiter))
			break ;
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}
