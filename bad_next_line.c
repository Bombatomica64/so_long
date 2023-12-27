/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bad_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:49:45 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/22 12:29:52 by lmicheli         ###   ########.fr       */
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

char	*ft_strjoin2(char *old_str, char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(sizeof(char) * (ft_strlen(old_str) + ft_strlen(buf) + 1));
	if (!res)
		return (0);
	i = -1;
	j = 0;
	if (old_str)
		while (old_str[++i] != '\0')
			res[i] = old_str[i];
	while (buf[j] != '\0')
		res[i++] = buf[j++];
	res[ft_strlen(old_str) + ft_strlen(buf)] = '\0';
	free(buf);
	return (res);
}
