/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:43:29 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/07 12:42:01 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	check_name(char *filename)
{
	char	*here_doc;
	int		i;

	i = 0;
	here_doc = "here_doc";
	while (filename[i] && here_doc[i] && filename[i] == here_doc[i])
		i++;
	if (filename[i] == '\0' && here_doc[i] == '\0')
		return (0);
	return (1);
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
