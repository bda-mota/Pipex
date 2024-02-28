/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:13:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/28 19:11:24 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	finish(t_pipex *pipex);

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (check_arguments(argc) == -1)
		return (-1);
	pipex.complete_env = find_env(env);
	build_env(&pipex);
	assign_variables(&pipex, argc, argv);
	check_files(&pipex);
	open_tube(&pipex);
	first_child(&pipex, argv[2]);
	second_child(&pipex, argv[3]);
	finish(&pipex);
}

void	finish(t_pipex *pipex)
{
	close_tubes(pipex);
	free_split(pipex->env);
	free(pipex->cmd1);
	free(pipex->cmd2);
}
