/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/27 12:12:28 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    assign_variables(t_pipex *pipex, char **argv)
{
    pipex->infile = argv[1];
    pipex->cmd1 = argv[2]; 
    pipex->cmd2 = argv[3];
    pipex->outfile = argv[4];   
}

int check_arguments(int argc)
{
    if (argc < 5)
        return (error(WARNING_1), error(WARNING_3), (FAILURE));
    else if (argc > 5)
        return (error (WARNING_2), error(WARNING_3), (FAILURE));
    else
        return (SUCESS);
}

void	error(char *msg_error)
{
	while (*msg_error)
    {
 		write (1, &*msg_error, 1);
		msg_error++;
    }
}
// void	close_tubes(t_pipex *pipex)
// {
// 	close(pipex->tube[0]);
// 	close(pipex->tube[1]);

// }

// void	check_file(char *path)
// {
// 	if (access(path, F_OK) == -1)
// 		exit(0);
// 	else
// 		ft_printf("achei\n");
// }


