/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:49:56 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 16:55:58 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	image_handling_after_villain_move_down(t_prgm *vr)
{
	char	*floor_tile_path;
	char	*player_tile_path;

	floor_tile_path = "./images/xpm/floor_tile_64x64.xpm";
	player_tile_path = "./images/xpm/player_v2_run_R_64x64_0.xpm";
	if (vr->map[vr->fcym][vr->fcxm - 1] == '0')
	{
		vr->img = mlx_xpm_file_to_image(vr->mlx, floor_tile_path,
				vr->wid, vr->hei);
		mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
			vr->fcxw - 64, vr->fcyw);
	}
	else if (vr->map[vr->fcym][vr->fcxm - 1] == 'P' )
	{
		vr->img = mlx_xpm_file_to_image(vr->mlx, player_tile_path,
				vr->wid, vr->hei);
		mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
			vr->fcxw - 64, vr->fcyw);
	}
}

void	image_handling_after_villain_move_up(t_prgm *vr)
{
	char	*floor_tile_path;
	char	*player_tile_path;

	floor_tile_path = "./images/xpm/floor_tile_64x64.xpm";
	player_tile_path = "./images/xpm/player_v2_run_R_64x64_0.xpm";
	if (vr->map[vr->fcym + 1][vr->fcxm - 1] == '0')
	{
		vr->img = mlx_xpm_file_to_image(vr->mlx, floor_tile_path,
				vr->wid, vr->hei);
		mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
			vr->fcxw - 64, vr->fcyw + 64);
	}
	else if (vr->map[vr->fcym + 1][vr->fcxm - 1] == 'P')
	{
		vr->img = mlx_xpm_file_to_image(vr->mlx, player_tile_path,
				vr->wid, vr->hei);
		mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
			vr->fcxw - 64, vr->fcyw + 64);
	}
}
