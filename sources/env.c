/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:57 by bda-mota          #+#    #+#             */
/*   Updated: 2024/03/05 23:28:49 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*find_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	ft_putstr_fd(WARNING_ENV, 2);
	return (NULL);
}

void	build_env(t_pipex *pipex, char **env)
{
	int		i;
	char	*aux;

	i = 0;
	pipex->complete_env = find_env(env);
	pipex->env = ft_split(pipex->complete_env, ':');
	if (pipex->env == NULL)
		set_error(pipex, 2, NULL);
	while (pipex->env[i])
	{
		aux = ft_strdup(pipex->env[i]);
		if (aux == NULL)
			break ;
		free(pipex->env[i]);
		pipex->env[i] = ft_strjoin(aux, "/");
		free(aux);
		i++;
	}
}

char	*add_cmd_env(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*aux;
	char	*aux_cmd;
	char	**take_first;

	i = 0;
	take_first = ft_split(cmd, ' ');
	if (take_first == NULL)
		set_error(pipex, 2, NULL);
	aux = take_first[0];
	while (pipex->env[i])
	{
		aux_cmd = ft_strjoin(pipex->env[i], aux);
		if (access(aux_cmd, X_OK) == 0)
		{
			free_split(take_first);
			return (aux_cmd);
		}
		free(aux_cmd);
		i++;
	}
	free_split(take_first);
	return (NULL);
}
