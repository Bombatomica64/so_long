/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:49:45 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/19 18:33:44 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*bad_next_line(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line[ft_strlen(line) - 1] == '\n')
	{
		line = ft_strtrim(line, "\n");
	}
	return (line);
}
