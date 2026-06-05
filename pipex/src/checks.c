/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:51:27 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/14 21:03:40 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_files(char **av)
{
	int	fd1;
	int	fd2;

	fd1 = open_file(av[1], 0);
	fd2 = open_file(av[4], 1);
	if (fd1 < 0)
	{
		if (fd2 > 2)
			close(fd2);
	}
	if (fd2 < 0)
	{
		close(fd1);
		return ;
	}
	close(fd1);
	close(fd2);
	return ;
}
