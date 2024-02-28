/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:57:41 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/28 19:22:22 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	first_child(t_pipex *pipex, char *command)
{
	int	fd1;

	if (access(pipex->cmd1, F_OK) == -1)
		pipex->cmd1 = add_cmd_env(pipex, pipex->cmd1);
	if (access(pipex->infile, F_OK) == -1)
		return ;
	fd1 = open(pipex->infile, O_RDONLY);
	if (fd1 == -1)
		return ;
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		close(pipex->tube[0]);
		dup2(pipex->tube[1], STDOUT_FILENO);
		dup2(fd1, STDIN_FILENO);
		close(pipex->tube[1]);
		close(fd1);
		implement(pipex, command, pipex->cmd1);
	}
}

void	second_child(t_pipex *pipex, char *command)
{
	int	fd2;

	if (access(pipex->cmd2, F_OK) == -1)
		pipex->cmd2 = add_cmd_env(pipex, pipex->cmd2);
	fd2 = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd2 == -1)
		return ;
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		close(pipex->tube[1]);
		dup2(pipex->tube[0], STDIN_FILENO);
		dup2(fd2, STDOUT_FILENO);
		close(pipex->tube[0]);
		close(fd2);
		implement(pipex, command, pipex->cmd2);
	}
	if (pipex->cmd2 == NULL)
		error(WARNING_CMD_1);
}

void	implement(t_pipex *pipex, char *command, char *executable)
{
	pipex->argv_child = ft_split(command, ' ');
	if (executable == NULL)
		return ;
	execve(executable, pipex->argv_child, pipex->env);
}
