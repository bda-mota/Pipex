/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:27:57 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/27 11:34:18 by bda-mota         ###   ########.fr       */
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
	return (NULL);
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
}