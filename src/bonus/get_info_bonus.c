/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:26:41 by hmakino           #+#    #+#             */
/*   Updated: 2023/03/06 06:29:56 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	heredoc_to_fd(char *limiter);

void	get_io_file(int argc, char **argv, t_info *info)
{
	char	*infile;
	char	*outfile;
	char	*limiter;

	infile = argv[1];
	outfile = argv[argc - 1];
	limiter = argv[2];
	if (info->heredoc)
	{
		info->io_file[IN] = heredoc_to_fd(limiter);
		info->io_file[OUT] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (info->io_file[OUT] < 0)
			error_exit(0, "open");
		return ;
	}
	info->io_file[IN] = open(infile, O_RDONLY);
	if (info->io_file[IN] < 0)
	{
		if (errno == ENOENT)
			error_exit(0, infile);
		error_exit(0, "open");
	}
	info->io_file[OUT] = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (info->io_file[OUT] < 0)
		error_exit(0, "open");
}

void	get_env(char **env, t_info *info)
{
	if (env == NULL)
		error_exit(ERR_ENV, NULL);
	while (1)
	{
		if (*env == NULL)
			error_exit(ERR_PATH, NULL);
		if (!ft_strncmp("PATH=", *env, 5))
			break ;
		env++;
	}
	info->env = ft_split(*env + 5, ':');
	if (errno == ENOMEM)
		error_exit(0, "malloc");
}

void	get_cmd(char *cmd_arg, t_info *info)
{
	char	*tmp;

	tmp = ft_strchr(cmd_arg, ' ');
	if (tmp == NULL)
		info->cmd[0] = cmd_arg;
	else
	{
		cmd_arg[tmp - cmd_arg] = '\0';
		info->cmd[0] = cmd_arg;
		info->cmd[1] = tmp + 1;
	}
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

static int	heredoc_to_fd(char *limiter)
{
	int		fd[2];
	char	*line;

	if (pipe(fd) < 0)
		error_exit(0, "pipe");
	while (1)
	{
		line = ft_readline("heredoc> ");
		if (line == NULL || !ft_strcmp(line, limiter))
			break ;
		ft_putendl_fd(line, fd[1]);
		free(line);
	}
	free(line);
	close(fd[OUT]);
	return (fd[IN]);
}
