/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:23:23 by falarm            #+#    #+#             */
/*   Updated: 2022/03/25 18:38:19 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_fd(int *fd1, int *fd2, char **argv)
{
	*fd1 = open(argv[1], O_RDONLY);
	if (*fd1 == -1)
		error_file(argv[1]);
	*fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (*fd2 == -1)
		error_file(argv[4]);
}

char	**find_path(char **env)
{
	char	**arr;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			arr = ft_split(env[i] + 5, ':');
			if (!arr)
				error_process();
			return (arr);
		}
		i++;
	}
	return (NULL);
}

char	*get_line(char *cmd, char **arr)
{
	char	*tmp;
	char	*line;
	int		i;

	i = 0;
	while (arr[i])
	{
		tmp = ft_strjoin(arr[i], "/");
		line = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(line, F_OK) == 0)
			return (line);
		else
			free(line);
		i++;
	}
	error_cmd(cmd);
	return (NULL);
}
