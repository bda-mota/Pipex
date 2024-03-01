/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:43:29 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/01 12:58:48 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_arguments(int argc)
{
	if (argc < 5)
		return (error(WARNING_ARGS_1), error(WARNING_ARGS_3), (FAILURE));
	else if (argc > 5)
		return (error (WARNING_ARGS_2), error(WARNING_ARGS_3), (FAILURE));
	else
		return (SUCESS);
}

void	check_files(t_pipex *pipex)
{
	if (access(pipex->infile, F_OK) == -1)
	{
		error(WARNING_FILES_1);
		error(pipex->infile);
		write(1, "\n", 1);
	}
	if (access(pipex->infile, F_OK) == 0 && access(pipex->infile, R_OK) == -1)
		error(WARNING_FILES_2);
	if (access(pipex->outfile, F_OK) == -1)
		return ;
	if (access(pipex->outfile, W_OK) == -1)
		error(WARNING_FILES_3);
}

void	check_commands(t_pipex *pipex, char **argv, int argc)
{
	if (access(pipex->cmd1, F_OK) == -1)
		pipex->cmd1 = add_cmd_env(pipex, pipex->cmd1);
	if (access(pipex->cmd1, F_OK) == -1)
	{
		error(WARNING_CMD_1);
		error(argv[2]);
		write(1, "\n", 1);
	}
	if (access(pipex->cmd2, F_OK) == -1)
		pipex->cmd2 = add_cmd_env(pipex, pipex->cmd2);
	if (access(pipex->cmd2, F_OK) == -1)
	{
		error(WARNING_CMD_1);
		error(argv[argc - 1]);
		write(1, "\n", 1);
	}

}
