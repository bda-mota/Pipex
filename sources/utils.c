/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/06 17:29:54 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_tube(t_pipex *pipex)
{
	if (pipe(pipex->tube) == -1)
		set_error(pipex, 1, NULL);
	return (SUCESS);
}

void	close_tubes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	set_error(t_pipex *pipex, int type, char *msg_error)
{
	if (type == 1)
	{
		ft_putstr_fd(WARNING_FILES_1, 2);
		perror(msg_error);
	}
	else if (type == 2)
		ft_putstr_fd(WARNING_SPLIT, 2);
	else if (type == 127)
	{
		ft_putstr_fd(pipex->argv_child[0], 2);
		ft_putstr_fd(WARNING_CMD_1, 2);
		free_split(pipex->argv_child);
		free_split(pipex->env);
	}
	exit(type);
}

void	free_split(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
