/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:56:51 by mochan            #+#    #+#             */
/*   Updated: 2022/08/13 01:29:55 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_image_player_mapping_lf(t_prgm *vars, int n)
{	
	if (n == 1)
		vars->path_img_plrl = "./images/xpm/player_v2_run_L_64x64_0.xpm";
	if (n == 2)
		vars->path_img_plrl = "./images/xpm/player_v2_run_L_64x64_1.xpm";
	if (n == 3)
		vars->path_img_plrl = "./images/xpm/player_v2_run_L_64x64_2.xpm";
	if (n == 4)
		vars->path_img_plrl = "./images/xpm/player_v2_run_L_64x64_3.xpm";
	if (n == 5)
		vars->path_img_plrl = "./images/xpm/player_v2_run_L_64x64_4.xpm";
}

void	ft_update_image_player_lf(t_prgm *vars, int n)
{
	ft_image_player_mapping_lf(vars, n);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path_img_plrl,
			vars->wid, vars->hei);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->pxw, vars->pyw);
}
