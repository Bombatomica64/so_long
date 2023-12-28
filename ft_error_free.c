/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmicheli <lmicheli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:24:05 by lmicheli          #+#    #+#             */
/*   Updated: 2023/12/27 18:25:29 by lmicheli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_free(t_datamap *data)
{
	ft_destroy_images(data);
	ft_free_map_and_enemies(data);
	ft_free_moves_and_mlx(data);
	exit(0);
}
