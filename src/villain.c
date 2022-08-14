/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:13:33 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 15:18:53 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_villain_pos(t_prgm *vr)
{
	if (vr->fc_located == 1)
	{
		ft_printf("=====BEFORE INIT================\n");
		ft_printf("vr->vxm = %d\n", vr->vxm);
		ft_printf("vr->vym = %d\n", vr->vym);
		ft_printf("vr->vxw = %d\n", vr->vxw);
		ft_printf("vr->vyw = %d\n", vr->vyw);
		vr->map[vr->fcym][vr->fcxm - 1] = 'V';
		vr->vxm = vr->fcxm - 1;
		vr->vym = vr->fcym;
		vr->vxw = vr->vxm * 64;
		vr->vyw = vr->vym * 64;
		vr->b_activate_vill = 1;
		ft_printf("=====AFTER INIT================\n");
		ft_printf("vr->vxm = %d\n", vr->vxm);
		ft_printf("vr->vym = %d\n", vr->vym);
		ft_printf("vr->vxw = %d\n", vr->vxw);
		ft_printf("vr->vyw = %d\n", vr->vyw);
	
	}
}

void	find_villain(t_prgm *vr)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (ft_strchr(vr->map[j], 'V') == 0)
		j++;
	while (vr->map[j][i] != 'V')
		i++;
	vr->vxm = i;
	vr->vym = j;
	vr->vxw = i * 64;
	vr->vyw = j * 64;
}

void	ft_image_villain_mapping_rg(t_prgm *vars, int n)
{	
	if (n == 1)
		vars->path_img_vilr = "./images/xpm/villain_run_v2_64x64_0.xpm";
	if (n == 2)
		vars->path_img_vilr = "./images/xpm/villain_run_v2_64x64_1.xpm";
	if (n == 3)
		vars->path_img_vilr = "./images/xpm/villain_run_v2_64x64_2.xpm";
	if (n == 4)
		vars->path_img_vilr = "./images/xpm/villain_run_v2_64x64_3.xpm";
	if (n == 5)
		vars->path_img_vilr = "./images/xpm/villain_run_v2_64x64_4.xpm";
}


void	ft_update_image_villain_rg_down(t_prgm *vr, int n)
{
	char	*floor_tile_path;
	
	floor_tile_path = "./images/xpm/floor_tile_64x64.xpm";
	ft_image_villain_mapping_rg(vr, n);
	vr->img = mlx_xpm_file_to_image(vr->mlx, vr->path_img_vilr,
			vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
		vr->fcxw - 64, vr->fcyw + 64);
	vr->map[vr->fcym + 1][vr->fcxm - 1] = 'V';
	vr->map[vr->fcym][vr->fcxm - 1] = '0';
	find_villain(vr);
	if (vr->map[vr->fcym][vr->fcxm - 1] == '0')
	{
		vr->img = mlx_xpm_file_to_image(vr->mlx, floor_tile_path,
			vr->wid, vr->hei);
	}
	else if (vr->map[vr->fcym][vr->fcxm - 1] == 'P')
	{
		vr->img = mlx_xpm_file_to_image(vr->mlx, vr->path_img_plrl,
			vr->wid, vr->hei);
	}
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
		vr->fcxw - 64, vr->fcyw);
}

void	ft_update_image_villain_rg_up(t_prgm *vr, int n)
{
	char	*floor_tile_path;
	
	floor_tile_path = "./images/xpm/floor_tile_64x64.xpm";
	ft_image_villain_mapping_rg(vr, n);
	vr->img = mlx_xpm_file_to_image(vr->mlx, vr->path_img_vilr,
			vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
		vr->fcxw - 64, vr->fcyw);
	vr->map[vr->fcym][vr->fcxm - 1] = 'V';
	vr->map[vr->fcym + 1][vr->fcxm - 1] = '0';
	find_villain(vr);
	vr->img = mlx_xpm_file_to_image(vr->mlx, floor_tile_path,
			vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
		vr->fcxw - 64, vr->fcyw + 64);
}

int	ct_to_frame_4(int counter, int frames)
{
	return (counter / SPEED_4 % frames);
}

void	villain_motion(t_prgm *vr, int n)
{
	if (vr->b_activate_vill == 1)
	{
		char	*floor_tile_path;

		floor_tile_path = "./images/xpm/floor_tile_64x64.xpm";
		if (n == 1)
		{
			ft_update_image_villain_rg_down(vr, ct_to_frame_3(vr->counter, 5) + 1);
		}
		if (n == 2)
		{
			ft_update_image_villain_rg_up(vr, ct_to_frame_3(vr->counter, 5) + 1);
		}
	}
}

int	ct_to_frame_3(int counter, int frames)
{
	return (counter / SPEED_3 % frames);
}

void	animate_villain(t_prgm *vr)
{
	if (vr->b_activate_vill==1 && vr->b_v_right == 1)
	{
		vr->b_counter_vil_mot++;
		villain_motion(vr, ct_to_frame_4(vr->b_counter_vil_mot++, 2) + 1);
		if (vr->pxm == vr->vxm && vr->pym == vr->vym)
			ft_close_window(vr);
	}
}
