/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:54:01 by mochan            #+#    #+#             */
/*   Updated: 2022/08/10 20:44:51 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_move_up_to_window(t_prgm *vr)
{
	char	*pl_path;
	char	*ti_path;

	pl_path = "./images/xpm/player_v2_right_tile_64x64.xpm";
	ti_path = "./images/xpm/floor_tile_64x64.xpm";
	vr->img = mlx_xpm_file_to_image(vr->mlx, pl_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pxw, vr->pyw - 64);
	vr->img = mlx_xpm_file_to_image(vr->mlx, ti_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pxw, vr->pyw);
}

void	put_move_down_to_window(t_prgm *vr)
{
	char	*pl_path;
	char	*ti_path;

	pl_path = "./images/xpm/player_v2_right_tile_64x64.xpm";
	ti_path = "./images/xpm/floor_tile_64x64.xpm";
	vr->img = mlx_xpm_file_to_image(vr->mlx, pl_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pxw, vr->pyw + 64);
	vr->img = mlx_xpm_file_to_image(vr->mlx, ti_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pxw, vr->pyw);
}

void	put_move_right_to_window(t_prgm *vr)
{
	char	*pl_path;
	char	*ti_path;

	pl_path = "./images/xpm/player_v2_right_tile_64x64.xpm";
	ti_path = "./images/xpm/floor_tile_64x64.xpm";
	vr->img = mlx_xpm_file_to_image(vr->mlx, pl_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pxw + 64, vr->pyw);
	vr->img = mlx_xpm_file_to_image(vr->mlx, ti_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pxw, vr->pyw);
}

void	put_move_left_to_window(t_prgm *vr)
{
	char	*pl_path;
	char	*ti_path;

	pl_path = "./images/xpm/player_v2_left_tile_64x64.xpm";
	ti_path = "./images/xpm/floor_tile_64x64.xpm";
	vr->img = mlx_xpm_file_to_image(vr->mlx, pl_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pxw - 64, vr->pyw);
	vr->img = mlx_xpm_file_to_image(vr->mlx, ti_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pxw, vr->pyw);
}

void	put_black_patch_to_window(t_prgm *vr)
{
	char	*bk_path;

	bk_path = "./images/xpm/black_tile_64x64.xpm";
	vr->img = mlx_xpm_file_to_image(vr->mlx, bk_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, 448, 704);
	vr->img = mlx_xpm_file_to_image(vr->mlx, bk_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, 512, 704);
}
