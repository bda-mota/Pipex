/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:13:30 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/28 16:07:45 by bda-mota         ###   ########.fr       */
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

# define SUCESS 1
# define FAILURE -1
# define WARNING_ENV "Path not found.\n"
# define WARNING_ARGS_1 "Misssing arguments.\n"
# define WARNING_ARGS_2 "Too many arguments.\n"
# define WARNING_ARGS_3 "Should be executed as: ./pipex file1 cmd1 cmd2 file2.\n"
# define WARNING_FILES_1 "Non-existent file.\n"
# define WARNING_FILES_2 "File unreadable.\n"
# define WARNING_FILES_3 "Destination file is not writeable.\n"
# define WARNING_FILES_4 "Error opening the file.\n"
# define WARNING_CMD_1 "Non-existent command.\n"
# define WARNING_CMD_2 "Unreadable command.\n"
# define WARNING_CMD_3 "Unexecutable command.\n"
# define WARNING_TUBE "Error create the tube.\n"

typedef struct s_pipex
{
	char	**env;
	char	**argv_child;
	char	*complete_env;
	char	*cmd1;
	char	*cmd2;
	char	*infile;
	char	*outfile;
	int		tube[2];
	int		pid1;
	int		pid2;
}	t_pipex;

int		check_arguments(int argc);
char	*find_env(char **path);
void	build_env(t_pipex *pipex);
char	*add_cmd_env(t_pipex *pipex, char *cmd);
void	error(char *msg_error);
void	assign_variables(t_pipex *pipex, int argc, char **argv);
int		check_files(t_pipex *pipex);
int		check_commands(t_pipex *pipex);
int		open_tube(t_pipex *pipex);
void	close_tubes(t_pipex *pipex);
void	first_child(t_pipex *pipex, char *command);
void	second_child(t_pipex *pipex, char *command);
void	free_split(char **matrix);
void	implement(t_pipex *pipex, char *command, char *executable);

#endif
