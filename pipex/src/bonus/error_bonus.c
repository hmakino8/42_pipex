/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiroaki <hiroaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 07:25:52 by hmakino           #+#    #+#             */
/*   Updated: 2022/07/03 02:42:28 by hiroaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_fail(int err_num, char *err, t_pipex *px)
{
	if (err_num == ERR_ARG)
		ft_dprintf(2, "%s\n", "Error: too few arguments");
	if (err_num == ERR_HEREDOC)
		ft_dprintf(2, "%s\n", "Error: here_doc: fail to read");
	if (err_num == ERR_PATH)
		ft_dprintf(2, "%s\n", "Error: path does not exist");
	if (err_num == ERR_CMD)
		ft_dprintf(2, "%s%s\n", "Error: command not found: ", err);
	if (!err_num)
		perror(err);
	if (px->flag_h == FLAGGED_HEREDOC)
		unlink(".heredoc");
	free_alloc_memory(px);
	exit(EXIT_FAILURE);
}
