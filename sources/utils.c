/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/28 13:29:06 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	assign_variables(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = argv[1];
	pipex->cmd1 = argv[2];
	pipex->cmd2 = argv[3];
	pipex->outfile = argv[argc - 1];
	pipex->cmd_qtd = argc - 3;
}

void	error(char *msg_error)
{
	while (*msg_error)
	{
		write(1, &*msg_error, 1);
		msg_error++;
	}
}

int	open_files(t_pipex *pipex)
{
	pipex->fd1 = open(pipex->infile, O_RDONLY);
	if (pipex->fd1 == -1)
		return (error(WARNING_FILES_4), FAILURE);
	pipex->fd2 = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd2 == -1)
		return (error(WARNING_FILES_4), FAILURE);
	return (SUCESS);
}

// void	close_tubes(t_pipex *pipex)
// {
// 	close(pipex->tube[0]);
// 	close(pipex->tube[1]);

// }

// void	check_file(char *path)
// {
// 	if (access(path, F_OK) == -1)
// 		exit(0);
// 	else
// 		ft_printf("achei\n");
// }


