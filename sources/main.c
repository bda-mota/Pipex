/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:13:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/05 13:21:44 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_memory(t_pipex *pipex);

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		status;

	build_pipex(&pipex, argc, argv, env);
	first_child(&pipex, argv[2]);
	second_child(&pipex, argv[3]);
	close_tubes(&pipex);
	waitpid(pipex.pid2, &status, 0);
	free_memory(&pipex);
	return (get_status(status));
}

void	build_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (check_arguments(argc) == 0)
		exit (0);
	assign_variables(pipex, argc, argv);
	build_env(pipex, env);
	check_commands(pipex);
	open_tube(pipex);
}

void	free_memory(t_pipex *pipex)
{
	if (pipex->env)
		free_split(pipex->env);
	if (pipex->cmd1)
		free(pipex->cmd1);
	if (pipex->cmd1)
		free(pipex->cmd2);
}
void	set_error(t_pipex *pipex, int type, char *msg_error)
{
	if (type == 1)
	{
		ft_putstr_fd(WARNING_FILES_1, 2);
		perror(msg_error);
	}
	else if (type == 127)
	{
		ft_putstr_fd(pipex->argv_child[0], 2);
		ft_putstr_fd(WARNING_CMD_1, 2);
		write(1, "\n", 1);
		free_split(pipex->argv_child);
		free_split(pipex->env);
	}
	exit(type);
}