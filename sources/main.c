/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:13:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/27 15:32:31 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;
	
	if (check_arguments(argc) == -1)
		return (-1);
	pipex.complete_env = find_env(env);
	build_env(&pipex);
	assign_variables(&pipex, argv);
	check_files(&pipex);
	check_commands(&pipex);
}

// if (argc == 3)
// 		return (-1);
// 	pipe(pipex.tube);
// 	pipex.pid1 = fork();
// 	if (pipex.pid1 == -1)
// 		return (-1);
// 	if (pipex.pid1 == 0)
// 	{
// 		close(pipex.tube[0]);
// 		dup2(pipex.tube[1], 1);
// 		check_path(argv[1]);
// 		execve("/usr/bin/ls", (char *[]){"ls", "-l", "../../", NULL}, 0);
// 	}
// 	pipex.pid2 = fork();
// 	if (pipex.pid2 == -1)
// 		return (-1);
// 	if (pipex.pid2 == 0)
// 	{
// 		dup2(pipex.tube[0], 0);
// 		close_tubes(&pipex);
// 		execve("/usr/bin/tr", (char *[]){"tr", "a-z", "A-Z", NULL}, 0);
// 	}
// 	close_tubes(&pipex);
// 	waitpid(pipex.pid1, NULL, 0);
// 	waitpid(pipex.pid2, NULL, 0);
// 	exit(0);
