/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:57:41 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/05 23:06:11 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	build_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (check_arguments(argc) == 0)
		exit (0);
	assign_variables(pipex, argc, argv);
	build_env(pipex, env);
	open_tube(pipex);
}

void	first_child(t_pipex *pipex, char *command)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		pipex->fd1 = open(pipex->infile, O_RDONLY);
		if (pipex->fd1 == -1)
		{
			close(pipex->tube[1]);
			free_split(pipex->env);
			set_error(pipex, 1, pipex->infile);	
		}
		close(pipex->tube[0]);
		dup2(pipex->tube[1], STDOUT_FILENO);
		dup2(pipex->fd1, STDIN_FILENO);
		close(pipex->tube[1]);
		close(pipex->fd1);
		implement(pipex, command);
	}
}

void	second_child(t_pipex *pipex, char *command)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		pipex->fd2 = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->fd2 == -1)
		{
			close(pipex->tube[0]);
			free_split(pipex->env);
			set_error(pipex, 1, pipex->outfile);			
		}
		close(pipex->tube[1]);
		dup2(pipex->tube[0], STDIN_FILENO);
		dup2(pipex->fd2, STDOUT_FILENO);
		close(pipex->tube[0]);
		close(pipex->fd2);
		implement(pipex, command);
	}
}

void	implement(t_pipex *pipex, char *command)
{
	char *executable;
	
	pipex->argv_child = ft_split(command, ' ');
	if (pipex->argv_child == NULL)
		set_error(pipex, 2, NULL);
	executable = check_command(pipex);
	if (executable == NULL)
		set_error(pipex, 127, NULL);
	execve(executable, pipex->argv_child, pipex->env);
}
