/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:13:33 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 16:57:29 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	ft_image_villain_mapping_rg(vr, n);
	vr->img = mlx_xpm_file_to_image(vr->mlx, vr->path_img_vilr,
			vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
		vr->fcxw - 64, vr->fcyw + 64);
	vr->map[vr->fcym + 1][vr->fcxm - 1] = 'V';
	vr->map[vr->fcym][vr->fcxm - 1] = '0';
	find_villain(vr);
	image_handling_after_villain_move_down(vr);
}

void	ft_update_image_villain_rg_up(t_prgm *vr, int n)
{
	ft_image_villain_mapping_rg(vr, n);
	vr->img = mlx_xpm_file_to_image(vr->mlx, vr->path_img_vilr,
			vr->wid, vr->hei);
	mlx_put_image_to_window(vr->mlx, vr->win, vr->img,
		vr->fcxw - 64, vr->fcyw);
	vr->map[vr->fcym][vr->fcxm - 1] = 'V';
	vr->map[vr->fcym + 1][vr->fcxm - 1] = '0';
	find_villain(vr);
	image_handling_after_villain_move_up(vr);
}

void	villain_motion(t_prgm *vr, int n)
{
	if (vr->b_activate_vill == 1)
	{
		if (n == 1)
		{
			ft_update_image_villain_rg_down(vr,
				ct_to_frame_3(vr->counter, 5) + 1);
		}
		if (n == 2)
		{
			ft_update_image_villain_rg_up(vr,
				ct_to_frame_3(vr->counter, 5) + 1);
		}
	}
}

void	animate_villain(t_prgm *vr)
{
	if (vr->b_activate_vill == 1 && vr->b_v_right == 1)
	{
		vr->b_counter_vil_mot++;
		villain_motion(vr, ct_to_frame_4(vr->b_counter_vil_mot++, 2) + 1);
		if (vr->pxm == vr->vxm && vr->pym == vr->vym)
			ft_close_window(vr);
	}
}
