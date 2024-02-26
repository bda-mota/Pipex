/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:13:33 by bda-mota          #+#    #+#             */
/*   Updated: 2024/02/26 11:26:43 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	char	*s;

	s = argv[1];
	if (argc == 5)
		ft_printf("foi");
	else if (argc < 5)
	{
		ft_printf("Missign arguments.\n");
		ft_printf("Show execute like: ./pipex file1 cmd1 cmd2 file2\n");
	}
	else
	{
		ft_printf("Too many arguments\n");
		ft_printf("Show execute like: ./pipex file1 cmd1 cmd2 file2\n");
	}
}
