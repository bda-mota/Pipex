/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:20:42 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/07 12:22:02 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/src/libft.h"

// write
# include <unistd.h>
// waitpid
# include <sys/wait.h>
// read, write, open
# include <fcntl.h>
// malloc
# include <stdlib.h>
//perror
# include <stdio.h>

# define SUCESS 1
# define FAILURE 0
# define TRUE 1
# define FALSE 0
# define WARNING_ENV "Path not found.\n"
# define WARNING_ARGS_1 "Misssing arguments.\n"
# define WARNING_ARGS_2 "Try: ./pipex file1 cmd1 cm2 ... file2.\n"
# define WARNING_FILES_1 "No such file or directory: "
# define WARNING_CMD_1 ": command not found\n"
# define WARNING_TUBE "Error create the tube.\n"
# define WARNING_SPLIT "Error allocating memory.\n"

typedef struct s_pipex
{
	char	**entire_env;
	char	**env;
	char	**argv_child;
	char	*complete_env;
	char	*infile;
	char	*outfile;
	int		here_doc;
	int		qtd_cmd;
	int		tube[2];
	int		pid1;
	int		pid2;
	int		fd1;
	int		fd2;
}	t_pipex;

int		check_name(char *filename);
int		open_tube(t_pipex *pipex);
char	*add_cmd_env(t_pipex *pipex, char *cmd);
char	*check_command(t_pipex *pipex);
void	build_pipex(t_pipex *pipex, int argc, char **argv, char **env);
void	assign_variables(t_pipex *pipex, int argc, char **argv);
void	build_env(t_pipex *pipex, char **env);
void	close_tubes(t_pipex *pipex);
void	first_child(t_pipex *pipex, char *command);
void	second_child(t_pipex *pipex, char *command);
void	implement(t_pipex *pipex, char *command);
void	set_error(t_pipex *pipex, int type, char *msg_error);
void	free_split(char **matrix);

#endif
