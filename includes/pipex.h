/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:13:30 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/26 18:40:52 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/src/libft.h"

// write
# include <unistd.h>
// waitpid
# include <sys/wait.h>
// read, write, open
# include <fcntl.h>
// malloc
# include <stdlib.h>

# define WARNING_1 "Misssing arguments.\n"
# define WARNING_2 "Too many arguments\n"
# define WARNING_3 "Should be executed as: ./pipex file1 cmd1 cmd2 file2\n"
# define WARNING_4 "Non-exixtent command\n"
# define WARNING_G "error: open, write, read, pipe or fork"

typedef struct s_pipex
{
	int	tube[2];
	int	pid1;
	int	pid2;
	int	infile;
	int	outfile;
}	t_pipex;

void	error(char *msg_error);
void	close_tubes(t_pipex *pipex);
void	check_file(char *path);
void	add_path(char *path);
char	*check_env(char **path);

#endif
