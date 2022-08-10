/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:20:22 by mochan            #+#    #+#             */
/*   Updated: 2022/08/10 12:37:45 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_prgm *vr)
{
	char	*pl_path;
	char	*ti_path;

	pl_path = "./images/xpm/player_v2_right_tile_64x64.xpm";
	ti_path = "./images/xpm/floor_tile_64x64.xpm";
	if (vr->map[vr->pl_ym - 1][vr->pl_xm] == '1')
		return ;
	vr->img = mlx_xpm_file_to_image(vr->mlx, pl_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pl_xw,
		vr->pl_yw - 64);
	vr->img = mlx_xpm_file_to_image(vr->mlx, ti_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pl_xw,
		vr->pl_yw);
	if (vr->map[vr->pl_ym - 1][vr->pl_xm] == 'C')
	{
		vr->collect_nb--;
		vr->map[vr->pl_ym - 1][vr->pl_xm] = '0';
	}
	if (vr->map[vr->pl_ym - 1][vr->pl_xm] == 'E' && vr->collect_nb != 0)
		return ;
	if (vr->map[vr->pl_ym - 1][vr->pl_xm] == 'E' && vr->collect_nb == 0)
		ft_close_window(vr);
	vr->pl_ym -= 1;
	vr->pl_yw -= 64;
	vr->steps += 1;
	ft_printf("number of steps : %d\n", vr->steps);
}

void	move_down(t_prgm *vr)
{
	char	*pl_path;
	char	*ti_path;

	pl_path = "./images/xpm/player_v2_right_tile_64x64.xpm";
	ti_path = "./images/xpm/floor_tile_64x64.xpm";
	if (vr->map[vr->pl_ym + 1][vr->pl_xm] == '1')
		return ;
	vr->img = mlx_xpm_file_to_image(vr->mlx, pl_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pl_xw,
		vr->pl_yw + 64);
	vr->img = mlx_xpm_file_to_image(vr->mlx, ti_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pl_xw,
		vr->pl_yw);
	if (vr->map[vr->pl_ym + 1][vr->pl_xm] == 'C')
	{
		vr->collect_nb--;
		vr->map[vr->pl_ym + 1][vr->pl_xm] = '0';
	}
	if (vr->map[vr->pl_ym + 1][vr->pl_xm] == 'E' && vr->collect_nb != 0)
		return ;
	if (vr->map[vr->pl_ym + 1][vr->pl_xm] == 'E' && vr->collect_nb == 0)
		ft_close_window(vr);
	vr->pl_ym += 1;
	vr->pl_yw += 64;
	vr->steps += 1;
	ft_printf("number of steps : %d\n", vr->steps);
}

void	move_right(t_prgm *vr)
{
	char	*pl_path;
	char	*ti_path;

	pl_path = "./images/xpm/player_v2_right_tile_64x64.xpm";
	ti_path = "./images/xpm/floor_tile_64x64.xpm";
	if (vr->map[vr->pl_ym][vr->pl_xm + 1] == '1')
		return ;
	vr->img = mlx_xpm_file_to_image(vr->mlx, pl_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pl_xw + 64,
		vr->pl_yw);
	vr->img = mlx_xpm_file_to_image(vr->mlx, ti_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pl_xw,
		vr->pl_yw);
	if (vr->map[vr->pl_ym][vr->pl_xm + 1] == 'C')
	{
		vr->collect_nb--;
		vr->map[vr->pl_ym][vr->pl_xm + 1] = '0';
	}
	if (vr->map[vr->pl_ym][vr->pl_xm + 1] == 'E' && vr->collect_nb != 0)
		return ;
	if (vr->map[vr->pl_ym][vr->pl_xm + 1] == 'E' && vr->collect_nb == 0)
		ft_close_window(vr);
	vr->pl_xm += 1;
	vr->pl_xw += 64;
	vr->steps += 1;
	ft_printf("number of steps : %d\n", vr->steps);
}

void	move_left(t_prgm *vr)
{
	char	*pl_path;
	char	*ti_path;

	pl_path = "./images/xpm/player_v2_left_tile_64x64.xpm";
	ti_path = "./images/xpm/floor_tile_64x64.xpm";
	if (vr->map[vr->pl_ym][vr->pl_xm - 1] == '1')
		return ;
	vr->img = mlx_xpm_file_to_image(vr->mlx, pl_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pl_xw - 64,
		vr->pl_yw);
	vr->img = mlx_xpm_file_to_image(vr->mlx, ti_path, vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->pl_xw,
		vr->pl_yw);
	if (vr->map[vr->pl_ym][vr->pl_xm - 1] == 'C')
	{
		vr->collect_nb--;
		vr->map[vr->pl_ym][vr->pl_xm - 1] = '0';
	}
	if (vr->map[vr->pl_ym][vr->pl_xm - 1] == 'E' && vr->collect_nb != 0)
		return ;
	if (vr->map[vr->pl_ym][vr->pl_xm - 1] == 'E' && vr->collect_nb == 0)
		ft_close_window(vr);
	vr->pl_xm -= 1;
	vr->pl_xw -= 64;
	vr->steps += 1;
	ft_printf("number of steps : %d\n", vr->steps);
}
