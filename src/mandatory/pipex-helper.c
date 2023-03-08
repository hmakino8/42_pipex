/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:32:17 by hiroaki           #+#    #+#             */
/*   Updated: 2023/03/09 06:26:46 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_double_ptr(char **d_ptr)
{
	int	i;

	i = 0;
	while (d_ptr && d_ptr[i])
	{
		free(d_ptr[i]);
		i++;
	}
	free(d_ptr);
}

void	error_exit(int sig, char *path)
{
	int	fd;
	int	stat;

	fd = STDERR_FILENO;
	stat = EXIT_FAILURE;
	ft_putstr_fd("pipex: ", fd);
	if (sig == ERR_PATH || sig == ERR_CMD)
	{
		stat = 127;
		ft_putstr_fd(path, fd);
		if (sig == ERR_PATH)
			ft_putendl_fd(": No such file or directory", fd);
		else
			ft_putendl_fd(": command not found", fd);
	}
	else if (sig == ERR_ENV)
		ft_putendl_fd("invalid environment variable", fd);
	else
		perror(path);
	exit(stat);
}

char	*ft_readline(char *prompt)
{
	char	*line;
	char	*ret;

	ft_putstr_fd(prompt, STDERR_FILENO);
	line = get_next_line(STDIN_FILENO);
	if (line == NULL)
		return (NULL);
	ret = ft_strtrim(line, "\n");
	free(line);
	return (ret);
}
