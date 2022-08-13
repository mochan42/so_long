/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:13:33 by mochan            #+#    #+#             */
/*   Updated: 2022/08/13 20:33:15 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_villain_pos(t_prgm *vr)
{
	if (vr->fc_located == 1)
	{
		vr->vxm = vr->fcxm - 1;
		vr->vym = vr->fcym;
		vr->vxw = vr->vxm * 64;
		vr->vyw = vr->vym * 64;
		vr->b_activate_vill = 1;
	}
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

void	ft_update_image_villain_rg(t_prgm *vars, int n)
{
	char	*floor_tile_path;
	
	floor_tile_path = "./images/xpm/floor_tile_64x64.xpm";
	ft_image_villain_mapping_rg(vars, n);
	vars->img = mlx_xpm_file_to_image(vars->mlx, vars->path_img_vilr,
			vars->wid, vars->hei);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->vxw, vars->vyw);
	vars->img = mlx_xpm_file_to_image(vars->mlx, floor_tile_path,
			vars->wid, vars->hei);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img,
		vars->vxw, vars->vyw - 64);
}

int	ct_to_frame_4(int counter, int frames)
{
	return (counter / SPEED_4 % frames);
}

void	villain_motion(t_prgm *vr, int n)
{
	char	*floor_tile_path;

	floor_tile_path = "./images/xpm/floor_tile_64x64.xpm";
	// if(vr->map[vr->vym][vr->vyx + 1] != 'E' && vr->map[vr->vym][vr->vyx + 1] != 'E'
	// 	&& vr->map[vr->vym][vr->vyx + 2] != 'C' && vr->map[vr->vym][vr->vyx + 2] != 'C')
	// {

	if (n % 2 == 0)
	{
		// usleep(100000);
		vr->vym += 1;
		vr->vyw = vr->vym * 64;
		ft_printf("vr->vxm is : %d\n", vr->vxm);
		ft_printf("vr->vym is : %d\n", vr->vym);
		ft_printf("vr->vxw is : %d\n", vr->vxw);
		ft_printf("vr->vyw is : %d\n", vr->vyw);
		ft_update_image_villain_rg(vr, ct_to_frame_4(vr->counter, 2) + 1);
	}
	if ((n+1) % 2 == 0)
	{
		// usleep(100000);
		vr->vym -= 1;
		vr->vyw = vr->vym * 64;
		ft_printf("vr->vxm is : %d\n", vr->vxm);
		ft_printf("vr->vym is : %d\n", vr->vym);
		ft_printf("vr->vxw is : %d\n", vr->vxw);
		ft_printf("vr->vyw is : %d\n", vr->vyw);
		ft_update_image_villain_rg(vr, ct_to_frame_4(vr->counter, 2) + 1);
	}
	// if (n == 2)
	// {
	// 	vr->vxm += 1;
	// 	vr->vxw = vr->vxm * 64;
	// }
	// if (n == 3)
	// {
	// 	vr->vxm += 1;
	// 	vr->vxw = vr->vxm * 64;
	// }
	// if (n == 4)
	// {
	// 	vr->vym += 1;
	// 	vr->vyw = vr->vym * 64;
	// }
	// if (n == 5)
	// {
	// 	vr->vym += 1;
	// 	vr->vyw = vr->vym * 64;
	// }
	// if (n == 6)
	// {
	// 	vr->vxm -= 1;
	// 	vr->vxw = vr->vxm * 64;
	// }	
	// if (n == 7)
	// {
	// 	vr->vxm -= 1;
	// 	vr->vxw = vr->vxm * 64;
	// }	
	// if (n == 8)
	// {
	// 	vr->vym -= 1;
	// 	vr->vyw = vr->vym * 64;
	// }
	// }
}


int	ct_to_frame_3(int counter, int frames)
{
	return (counter / SPEED_3 % frames);
}

void	animate_villain(t_prgm *vr)
{
	if (vr->b_activate_vill==1 && vr->b_v_right == 1)
	{
		vr->counter++;
		ft_update_image_villain_rg(vr, ct_to_frame_3(vr->counter, 5) + 1);
		villain_motion(vr, ct_to_frame_4(vr->counter, 2) + 1);
	}
	// else if (vr->b_activate_vill==1 && vr->b_v_left == 1)
	// {
	// 	vr->counter++;
	// 	ft_update_image_villain_lf(vr, ct_to_frame_2(vr->counter, 5) + 1);
	// }
}
