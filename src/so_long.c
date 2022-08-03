/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/03 13:23:25 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	printf("exit so_long");
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if(vars)
		printf("keycode is : %d\n", keycode);
	if(keycode == 6)
		printf("Player go up\n");
	if(keycode == 12)
		printf("Player go down\n");
	if(keycode == 1)
		printf("Player go left\n");
	if(keycode == 2)
		printf("Player go right\n");
	if(keycode == 53)
		ft_close_window(vars);
	return (0);
}

int	main()
{	
	t_vars	vars;
	t_data	floor_tile;
	
	vars.mlx = mlx_init();
	floor_tile.img = mlx_xpm_file_to_image(vars.mlx, floor_1.xpm, 16, 16);
	floor_tile.addr = mlx_get_data_addr(floor_tile.img, floor_tile.bits_per_pixel, floor_tile.line_length, floor_tile.endian);
	printf("bbp %d\n", floor_tile.bits_per_pixel);
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
	mlx_loop(vars.mlx);
}

