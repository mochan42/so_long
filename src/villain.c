/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:13:33 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 00:58:11 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_villain_pos(t_prgm *vr)
{
	if (vr->fc_located == 1)
	{
		// ft_printf("-----------------------------------\n");
		// ft_printf("BEFORE init enemy\n");
		// ft_printf("vr->b_activate_vill is : %d\n", vr->b_activate_vill);
		// ft_printf("vr->fcxm is : %d\n", vr->fcxm);
		// ft_printf("vr->fcym is : %d\n", vr->fcym);
		// ft_printf("vr->vxm is : %d\n", vr->vxm);
		// ft_printf("vr->vym is : %d\n", vr->vym);
		// ft_printf("vr->fcxw is : %d\n", vr->fcxw);
		// ft_printf("vr->fcyw is : %d\n", vr->fcyw);
		// ft_printf("vr->vxw is : %d\n", vr->vxw);
		// ft_printf("vr->vyw is : %d\n", vr->vyw);
		vr->map[vr->fcym][vr->fcxm - 1] = 'V';
		vr->vxm = vr->fcxm - 1;
		vr->vym = vr->fcym;
		vr->vxw = vr->vxm * 64;
		vr->vyw = vr->vym * 64;
		vr->b_activate_vill = 1;
		// ft_printf("====================================\n");
		// ft_printf("AFTER init enemy\n");
		// ft_printf("vr->b_activate_vill is : %d\n", vr->b_activate_vill);
		// ft_printf("vr->fcxm is : %d\n", vr->fcxm);
		// ft_printf("vr->fcym is : %d\n", vr->fcym);
		// ft_printf("vr->vxm is : %d\n", vr->vxm);
		// ft_printf("vr->vym is : %d\n", vr->vym);
		// ft_printf("vr->fcxw is : %d\n", vr->fcxw);
		// ft_printf("vr->fcyw is : %d\n", vr->fcyw);
		// ft_printf("vr->vxw is : %d\n", vr->vxw);
		// ft_printf("vr->vyw is : %d\n", vr->vyw);
		// ft_printf("-----------------------------------\n");
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
	find_villain(vr);
	vr->img = mlx_xpm_file_to_image(vr->mlx, floor_tile_path,
			vr->wid, vr->hei);
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
		// if(vr->map[vr->vym][vr->vyx + 1] != 'E' && vr->map[vr->vym][vr->vyx + 1] != 'E'
		// 	&& vr->map[vr->vym][vr->vyx + 2] != 'C' && vr->map[vr->vym][vr->vyx + 2] != 'C')
		// {
		ft_printf("\t\tvr->counter = %d\n\n", vr->counter);
		ft_printf("\t\tct_to_frame_4(vr->counter, 2) + 1 = %d\n\n", ct_to_frame_4(vr->counter, 2) + 1);
		// if (n % 2 == 0)
		if (n == 1)
		{
			// usleep(100000);
			// vr->vym += 1;
			// vr->vyw = vr->vym * 64;
			// ft_printf("-----------------------------------\n");
			// ft_printf("n == 1\n");
			// ft_printf("vr->fcxm is : %d\n", vr->fcxm);
			// ft_printf("vr->fcym is : %d\n", vr->fcym);
			// ft_printf("vr->vxm is : %d\n", vr->vxm);
			// ft_printf("vr->vym is : %d\n", vr->vym);
			// ft_printf("vr->fcxw is : %d\n", vr->fcxw);
			// ft_printf("vr->fcyw is : %d\n", vr->fcyw);
			// ft_printf("vr->vxw is : %d\n", vr->vxw);
			// ft_printf("vr->vyw is : %d\n", vr->vyw);
			ft_update_image_villain_rg_down(vr, ct_to_frame_4(vr->counter, 2) + 1);
			// ft_printf("============AFTER UPDATE============\n");
			// ft_printf("vr->fcxm is : %d\n", vr->fcxm);
			// ft_printf("vr->fcym is : %d\n", vr->fcym);
			// ft_printf("vr->vxm is : %d\n", vr->vxm);
			// ft_printf("vr->vym is : %d\n", vr->vym);
			// ft_printf("vr->fcxw is : %d\n", vr->fcxw);
			// ft_printf("vr->fcyw is : %d\n", vr->fcyw);
			// ft_printf("vr->vxw is : %d\n", vr->vxw);
			// ft_printf("vr->vyw is : %d\n", vr->vyw);
			// ft_printf("-----------------------------------\n");
		}
		// if ((n+1) % 2 == 0)
		if (n == 2)
		{
			// usleep(100000);
			// vr->vym -= 1;
			// vr->vyw = vr->vym * 64;
			// ft_printf("-----------------------------------\n");
			// ft_printf("n == 2\n");
			// ft_printf("vr->vxm is : %d\n", vr->vxm);
			// ft_printf("vr->vym is : %d\n", vr->vym);
			// ft_printf("vr->vxw is : %d\n", vr->vxw);
			// ft_printf("vr->vyw is : %d\n", vr->vyw);
			ft_update_image_villain_rg_up(vr, ct_to_frame_4(vr->counter, 2) + 1);
			// ft_printf("============AFTER UPDATE============\n");
			// ft_printf("vr->vxm is : %d\n", vr->vxm);
			// ft_printf("vr->vym is : %d\n", vr->vym);
			// ft_printf("vr->vxw is : %d\n", vr->vxw);
			// ft_printf("vr->vyw is : %d\n", vr->vyw);
			// ft_printf("-----------------------------------\n");
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
}


int	ct_to_frame_3(int counter, int frames)
{
	return (counter / SPEED_3 % frames);
}

void	animate_villain(t_prgm *vr)
{
	if (vr->b_activate_vill==1 && vr->b_v_right == 1)
	{
		// vr->counter_vil_mot++;
		// ft_update_image_villain_rg(vr, ct_to_frame_3(vr->counter_vil_mot, 5) + 1);
		villain_motion(vr, ct_to_frame_4(vr->counter, 2) + 1);
		// usleep(100000);
		// villain_motion(vr);
	}
	// else if (vr->b_activate_vill==1 && vr->b_v_left == 1)
	// {
	// 	vr->counter++;
	// 	ft_update_image_villain_lf(vr, ct_to_frame_2(vr->counter, 5) + 1);
	// }
}
