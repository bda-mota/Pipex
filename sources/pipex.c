/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:57:41 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/04 15:51:59 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_pipex *pipex, char *command)
{
	if (access(pipex->infile, F_OK) == -1)
		return ;
	pipex->fd1 = open(pipex->infile, O_RDONLY);
	if (pipex->fd1 == -1)
		return ;
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		close(pipex->tube[0]);
		dup2(pipex->tube[1], STDOUT_FILENO);
		dup2(pipex->fd1, STDIN_FILENO);
		close(pipex->tube[1]);
		close(pipex->fd1);
		implement(pipex, command, pipex->cmd1);
	}
}

void	second_child(t_pipex *pipex, char *command)
{
	pipex->fd2 = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd2 == -1)
		return ;
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		close(pipex->tube[1]);
		dup2(pipex->fd2, STDOUT_FILENO);
		dup2(pipex->tube[0], STDIN_FILENO);
		close(pipex->tube[0]);
		close(pipex->fd2);
		implement(pipex, command, pipex->cmd2);
	}
}

void	implement(t_pipex *pipex, char *command, char *executable)
{
	pipex->argv_child = ft_split(command, ' ');
	if (executable == NULL)
		exit(0);
	execve(executable, pipex->argv_child, pipex->env);
}
