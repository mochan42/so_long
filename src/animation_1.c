/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:47:07 by mochan            #+#    #+#             */
/*   Updated: 2022/08/12 14:24:55 by mochan           ###   ########.fr       */
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

static int	ct_to_frame(int counter, int frames)
{
	return (counter / SPEED % frames);
}

void	animate_1st_collectible(t_prgm *vr)
{	
	char	*path;

	path = NULL;
	if (vr->b_animate == 1 && vr->fc_located == 1)
	{
		vr->counter++;
		ft_update_image_1st_collectible(vr, ct_to_frame(vr->counter, 8) + 1);
		mlx_put_image_to_window(vr->mlx, vr->win, vr->img, vr->fcxw, vr->fcyw);
	}
}