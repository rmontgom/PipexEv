/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:02:27 by falarm            #+#    #+#             */
/*   Updated: 2022/03/22 20:58:57 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft_src/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>
# include <string.h>
# include <fcntl.h>

void	error_file(char *file);
void	error_process(void);
void	error_cmd(char *cmd);
char	**find_path(char **envp);
char	*get_line(char *cmd, char **arr);
void	check_fd(int *in, int *out, char **files);

#endif
