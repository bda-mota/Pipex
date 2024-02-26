/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:45:09 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/26 16:32:13 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(char *msg_error)
{
	while (*msg_error)
	{
		write (1, &*msg_error, 1);
		msg_error++;
	}
}

void	close_tubes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);

}
