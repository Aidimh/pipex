/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-aid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 22:02:13 by moel-aid          #+#    #+#             */
/*   Updated: 2025/03/01 11:26:28 by moel-aid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	exit_handler(int exit_status)
{
	if (exit_status == 1)
		ft_putstr_fd("./pipex infile 1st_cmd 2nd_cmd outfile\n", 2);
	else if (exit_status == 2)
	{
		ft_putstr_fd("./pipex no enough arguments\n", 2);
		ft_putstr_fd("./pipex infile 1st_cmd 2nd_cmd outfile\n", 2);
	}
	else if (exit_status == 3)
		ft_putstr_fd("Failed to open input file\n", 2);
	else if (exit_status == 4)
		ft_putstr_fd("Failed to open output file\n", 2);
}

int	open_file(char *file, int in_or_out)
{
	int	open_value;

	if (in_or_out == 0)
	{
		open_value = open(file, O_RDONLY);
	}
	if (in_or_out == 1)
	{
		open_value = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	return (open_value);
}

void	free_all_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*ft_getenv(char *name, char **env)
{
	int		i;
	int		j;
	int		s_total;
	char	*substring;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		substring = ft_substr(env[i], 0, j);
		s_total = ft_strlen(substring) + ft_strlen(name);
		if (ft_strncmp(substring, name, s_total) == 0)
		{
			free(substring);
			return (env[i] + j + 1);
		}
		free(substring);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*executable_path;
	char	**full_path;
	char	*path_part;
	char	**s_cmd;

	i = -1;
	full_path = ft_split(ft_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (full_path && full_path[++i])
	{
		path_part = ft_strjoin(full_path[i], "/");
		executable_path = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(executable_path, F_OK | X_OK) == 0)
		{
			free_all_tab(s_cmd);
			return (executable_path);
		}
		free(executable_path);
	}
	free_all_tab(full_path);
	free_all_tab(s_cmd);
	return (cmd);
}
