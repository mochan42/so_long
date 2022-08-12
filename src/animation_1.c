/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:47:07 by mochan            #+#    #+#             */
/*   Updated: 2022/08/12 10:27:51 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	find_1st_collectible(t_prgm *vr)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (ft_strchr(vr->map[j], 'C') == 0)
		j++;
	while (vr->map[j][i] != 'C')
		i++;
	vr->fcxw = i * 64;
	vr->fcyw = j * 64;
	vr->fc_located = 1;
}

void	ft_image_1st_collectible_mapping(t_prgm *vars, int n)
{	
	if (n == 1)
		vars->path_img = "./images/xpm/treasure_chest_0_64x64.xpm";
	if (n == 2)
		vars->path_img = "./images/xpm/treasure_chest_1_64x64.xpm";
	if (n == 3)
		vars->path_img = "./images/xpm/treasure_chest_2_64x64.xpm";
	if (n == 4)
		vars->path_img = "./images/xpm/treasure_chest_3_64x64.xpm";
	if (n == 5)
		vars->path_img = "./images/xpm/treasure_chest_4_64x64.xpm";
	if (n == 6)
		vars->path_img = "./images/xpm/treasure_chest_5_64x64.xpm";
	if (n == 7)
		vars->path_img = "./images/xpm/treasure_chest_6_64x64.xpm";
	if (n == 8)
		vars->path_img = "./images/xpm/treasure_chest_7_64x64.xpm";
}

void	ft_update_image_1st_collectible(t_prgm *vars, int n)
{
	ft_image_1st_collectible_mapping(vars, n);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path_img,
			vars->wid, vars->hei);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->fcxw, vars->fcyw);
}

void	animate_1st_collectible(t_prgm *vr)
{	
	char	*path;

	path = NULL;
	usleep(100000);
	if (vr->b_animate == 1 && vr->fc_located == 1)
	{
		vr->counter++;
		if (vr->counter % 1)
			ft_update_image_1st_collectible(vr, 1);
		if (vr->counter % 2)
			ft_update_image_1st_collectible(vr, 2);
		if (vr->counter % 3)
			ft_update_image_1st_collectible(vr, 3);
		if (vr->counter % 4)
			ft_update_image_1st_collectible(vr, 4);
		if (vr->counter % 5)
			ft_update_image_1st_collectible(vr, 5);
		if (vr->counter % 6)
			ft_update_image_1st_collectible(vr, 6);
		if (vr->counter % 7)
			ft_update_image_1st_collectible(vr, 7);
		if (vr->counter % 8)
			ft_update_image_1st_collectible(vr, 8);
		mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->fcxw, vr->fcyw);
	}
}
