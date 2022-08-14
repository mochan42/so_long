/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 22:05:45 by mochan            #+#    #+#             */
/*   Updated: 2022/08/13 01:09:18 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_image_player_mapping_rg(t_prgm *vars, int n)
{	
	if (n == 1)
		vars->path_img_plrr = "./images/xpm/player_v2_run_R_64x64_0.xpm";
	if (n == 2)
		vars->path_img_plrr = "./images/xpm/player_v2_run_R_64x64_1.xpm";
	if (n == 3)
		vars->path_img_plrr = "./images/xpm/player_v2_run_R_64x64_2.xpm";
	if (n == 4)
		vars->path_img_plrr = "./images/xpm/player_v2_run_R_64x64_3.xpm";
	if (n == 5)
		vars->path_img_plrr = "./images/xpm/player_v2_run_R_64x64_4.xpm";
}

void	ft_update_image_player_rg(t_prgm *vars, int n)
{
	ft_image_player_mapping_rg(vars, n);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path_img_plrr,
			vars->wid, vars->hei);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->pxw, vars->pyw);
}

int	ct_to_frame_2(int counter, int frames)
{
	return (counter / SPEED_2 % frames);
}

void	animate_player(t_prgm *vr)
{
	if (vr->b_right == 1)
	{
		vr->counter++;
		ft_update_image_player_rg(vr, ct_to_frame_2(vr->counter, 5) + 1);
	}
	else if (vr->b_left == 1)
	{
		vr->counter++;
		ft_update_image_player_lf(vr, ct_to_frame_2(vr->counter, 5) + 1);
	}
}
