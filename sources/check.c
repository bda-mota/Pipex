/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:43:29 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/05 13:15:57 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int check_arguments(int argc)
{
	if (argc < 5)
		return (error(WARNING_ARGS_1), error(WARNING_ARGS_3), (FAILURE));
	else if (argc > 5)
		return (error (WARNING_ARGS_2), error(WARNING_ARGS_3), (FAILURE));
	else
		return (SUCESS);
}

int	check_commands(t_pipex *pipex)
{
	if (access(pipex->cmd1, F_OK) == -1)
		pipex->cmd1 = add_cmd_env(pipex, pipex->cmd1);
	if (access(pipex->cmd2, F_OK) == -1)
		pipex->cmd2 = add_cmd_env(pipex, pipex->cmd2);
	if (pipex->cmd1 == NULL && pipex->cmd2 == NULL)
		return (error(WARNING_CMD_1), FAILURE);
	if (access(pipex->cmd2, R_OK) == -1)
		return (error(WARNING_CMD_2), FAILURE);
	if (access(pipex->cmd2, X_OK) == -1)
		return (error(WARNING_CMD_3), FAILURE);
	return (SUCESS);
}