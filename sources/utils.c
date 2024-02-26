/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/26 17:06:10 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(char *msg_error)
{
	while (*msg_error)
	{
		write (1, &*msg_error, 1);
		msg_error++;
	}
}

void	close_tubes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);

}

void	check_path(char *path)
{
	if (access(path, F_OK) == -1)
		add_path(path);
	else
		ft_printf("achei\n");
}

void	add_path(char *path)
{
	char	*new_path;

	new_path = ft_strjoin("/usr/bin/", path);
	if (access(new_path, F_OK) == -1)
		error(WARNING_4);
}
