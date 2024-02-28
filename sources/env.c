/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:57 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/28 15:10:57 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*find_env(char **env)
{
	int	i;
	int	len;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			len = ft_strlen(env[i]);
			env[i] = ft_substr(env[i], 5, len);
			return (env[i]);
		}
		i++;
	}
	return (error(WARNING_ENV), NULL);
}

void	build_env(t_pipex *pipex)
{
	int		i;
	char	*aux;

	i = 0;
	pipex->env = ft_split(pipex->complete_env, ':');
	while (pipex->env[i])
	{
		aux = pipex->env[i];
		pipex->env[i] = ft_strjoin(aux, "/");
		free(aux);
		aux = NULL;
		i++;
	}
	free(pipex->complete_env);
}

char	*add_cmd_env(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*aux_cmd;

	i = 0;
	aux_cmd = cmd;
	while (pipex->env[i])
	{
		aux_cmd = ft_strjoin(pipex->env[i], cmd);
		if (access(aux_cmd, F_OK) == 0)
			return (aux_cmd);
		i++;
	}
	free_split(pipex->env);
	free(aux_cmd);
	return (NULL);
}

void	free_split(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
