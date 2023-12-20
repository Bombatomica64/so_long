/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:49:45 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/20 18:01:46 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*bad_next_line(int fd)
{
	char	*line;
	char	*trimmed_line;

	line = get_next_line(fd);
	if (line == NULL)
	{
		free(line);
		return (NULL);
	}
	if (line[ft_strlen(line) - 1] == '\n')
	{
		trimmed_line = ft_strtrim(line, "\n");
		free(line);
		return (trimmed_line);
	}
	return (line);
}
