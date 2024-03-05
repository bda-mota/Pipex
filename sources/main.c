/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:13:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/05 15:15:10 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	int		status;

	build_pipex(&pipex, argc, argv, env);
	first_child(&pipex, argv[2]);
	second_child(&pipex, argv[3]);
	close_tubes(&pipex);
	waitpid(pipex.pid2, &status, 0);
	free_split(pipex.env);
	return (get_status(status));
}

int	get_status(int status)
{
	return (((status & 0xff00)) >> 8);
}

void	assign_variables(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = argv[1];
	pipex->outfile = argv[argc - 1];
}