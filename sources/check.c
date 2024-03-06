/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:43:29 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/06 16:39:18 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	check_arguments(int argc)
{
	if (argc < 5)
		return (ft_putstr_fd(WARNING_ARGS_1, 2), (FAILURE));
	else if (argc > 5)
		return (ft_putstr_fd(WARNING_ARGS_2, 2), (FAILURE));
	else
		return (SUCESS);
}

char	*check_command(t_pipex *pipex)
{
	char	*command;
	char	*complete_command;

	command = pipex->argv_child[0];
	if (access(command, X_OK) == 0)
		return (command);
	complete_command = add_cmd_env(pipex, command);
	return (complete_command);
}
