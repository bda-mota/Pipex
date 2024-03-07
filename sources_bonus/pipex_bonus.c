/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:57:41 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/07 12:45:12 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	build_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	if (argc < 5)
		set_error(pipex, 3, NULL);
	if (check_name(argv[1]) == 0)
		pipex->here_doc = TRUE;
	else
		pipex->here_doc = FALSE;
	if (pipex->here_doc && argc < 6)
		set_error(pipex, 3, NULL);
	pipex->entire_env = env;
	assign_variables(pipex, argc, argv);
	build_env(pipex, env);
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
