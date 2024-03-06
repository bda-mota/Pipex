/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:57:41 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/06 19:44:19 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	build_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (check_arguments(argc) == 0)
		exit (1);
	pipex->entire_env = env;
	assign_variables(pipex, argc, argv);
	build_env(pipex, env);
	open_tube(pipex);
}

void	implement(t_pipex *pipex, char *command)
{
	char	*executable;

	pipex->argv_child = ft_split(command, ' ');
	if (pipex->argv_child == NULL)
		set_error(pipex, 2, NULL);
	executable = check_command(pipex);
	if (executable == NULL)
		set_error(pipex, 127, NULL);
	execve(executable, pipex->argv_child, pipex->entire_env);
}
