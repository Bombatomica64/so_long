/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfalchi <tfalchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:05:55 by tfalchi           #+#    #+#             */
/*   Updated: 2023/12/18 17:12:48 by tfalchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstclear(t_data **tile, t_data **wall, void (*del)(void*))
{
	t_data	*temp;

	if (tile)
	{
		while (*tile)
		{
			temp = (*tile)->next;
			if (!tile || !del || !(*tile)
				return ;
			del(tile->content);
			free(tile);
			(*tile) = temp;
		}
	if (wall)
	{
		while (*wall)
		{
			temp = (*wall)->next;
			if (!wall || !del || !(*wall)
				return ;
			del(wall->content);
			free(wall);
			(*wall) = temp;
		}
	}
}