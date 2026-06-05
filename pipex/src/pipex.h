/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:02:28 by moel-aid          #+#    #+#             */
/*   Updated: 2025/02/03 17:06:10 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>

int		open_file(char *file, int n);
char	*ft_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	exec(char *cmd, char **env);
void	free_all_tab(char **tab);
void	exit_handler(int exit_status);
void	check_files(char **av);
#endif
