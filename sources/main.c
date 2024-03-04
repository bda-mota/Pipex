/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:13:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/04 15:52:55 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	finish(t_pipex *pipex);

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		status;

	if (check_arguments(argc) == 0)
		return (-1);
	build_env(&pipex, env);
	assign_variables(&pipex, argc, argv);
	check_files(&pipex);
	check_commands(&pipex, argv, argc);
	open_tube(&pipex);
	first_child(&pipex, argv[2]);
	second_child(&pipex, argv[3]);
	close_tubes(&pipex);
	waitpid(pipex.pid2, &status, 0);
	finish(&pipex);
	return (get_status(status));
}

void	finish(t_pipex *pipex)
{
	free_split(pipex->env);
	if (pipex->cmd1)
		free(pipex->cmd1);
	if (pipex->cmd1)
		free(pipex->cmd2);
}
