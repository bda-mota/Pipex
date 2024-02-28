/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:43:29 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/28 19:11:14 by bda-mota         ###   ########.fr       */
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
		error(WARNING_FILES_1);
	if (access(pipex->infile, F_OK) == 0 && access(pipex->infile, R_OK) == -1)
		error(WARNING_FILES_2);
	if (access(pipex->outfile, F_OK) == -1)
		return ;
	if (access(pipex->outfile, W_OK) == -1)
		error(WARNING_FILES_3);
}

