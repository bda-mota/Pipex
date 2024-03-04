/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/04 16:38:28 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	assign_variables(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = argv[1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	pipex->outfile = argv[argc - 1];
}

void	error(char *msg_error)
{
	while (*msg_error)
	{
		write(1, &*msg_error, 1);
		msg_error++;
	}
}

int	open_tube(t_pipex *pipex)
{
	if (pipe(pipex->tube) == -1)
		return (error(WARNING_TUBE), FAILURE);
	return (SUCESS);
}

void	close_tubes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

int	get_status(int status)
{
	return (((status & 0xff00)) >> 8);
}