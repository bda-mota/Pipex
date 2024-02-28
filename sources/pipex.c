/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:57:41 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/28 15:38:07 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_pipex *pipex)
{
	int	fd1;

	fd1 = open(pipex->infile, O_RDONLY);
	if (fd1 == -1)
		return (error(WARNING_FILES_4), FAILURE);
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		close(pipex->tube[0]);
		dup2(pipex->tube[1], STDOUT_FILENO);
		dup2(fd1, STDIN_FILENO);
		close(pipex->tube[1]);
		close(fd1);
		execute(pipex, pipex->cmd1);
	}
}

void	second_child(t_pipex *pipex)
{
	int	fd2;

	fd2 = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 == -1)
		return (error(WARNING_FILES_4), FAILURE);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		close(pipex->tube[1]);
		dup2(pipex->tube[0], STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		close(pipex->tube[0]);
		close(fd2);
		execute(pipex, pipex->cmd2);
	}
}
