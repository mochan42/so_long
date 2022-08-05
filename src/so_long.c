/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/05 11:13:02 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close_window(t_prgm *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("exit so_long");
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_prgm *vars)
{
	if(vars)
		ft_printf("keycode is : %d\n", keycode);
	if(keycode == 13)
		ft_printf("Player go up\n");
	if(keycode == 0)
		ft_printf("Player go down\n");
	if(keycode == 1)
		ft_printf("Player go left\n");
	if(keycode == 2)
		ft_printf("Player go right\n");
	if(keycode == 53)
		ft_close_window(vars);
	return (0);
}





int	main(int ac, char **av)
{	
	if(ac == 2)
	{
		t_prgm	vars;
		int		height;
		int		width;
		int		fd;
		char	path_floor_tile[]="./images/floor_tile_64x64.xpm";
		char	path_wall_tile[]="./images/wall_tile_64x64.xpm";
		char	path_player_tile[]="./images/player_tile_64x64.xpm";
		char	path_exit_tile[]="./images/exit_tile_64x64.xpm";
		char	path_collectible_tile[]="./images/collectible_tile_64x64.xpm";
		int		floor_tile;
		int		wall_tile;
		int		player_tile;
		int		exit_tile;
		int		collectible_tile;
		void	*img_floor;
		void	*img_wall;
		void	*img_player;
		void	*img_exit;
		void	*img_collectible;

		fd = open(av[1], O_RDONLY);
		height = 64;
		width = 64;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 15*width, 11*height, "so_long");
		
		img_floor = mlx_xpm_file_to_image(vars.mlx, path_floor_tile, &width, &height);
		floor_tile = mlx_put_image_to_window(vars.mlx, vars.win, img_floor, 64, 64);
		
		img_wall = mlx_xpm_file_to_image(vars.mlx, path_wall_tile, &width, &height);
		wall_tile = mlx_put_image_to_window(vars.mlx, vars.win, img_wall, 0, 0);
		
		img_player = mlx_xpm_file_to_image(vars.mlx, path_player_tile, &width, &height);
		player_tile = mlx_put_image_to_window(vars.mlx, vars.win, img_player, 64, 0);
		
		img_exit = mlx_xpm_file_to_image(vars.mlx, path_exit_tile, &width, &height);
		exit_tile = mlx_put_image_to_window(vars.mlx, vars.win, img_exit, 128, 0);
		
		img_collectible = mlx_xpm_file_to_image(vars.mlx, path_collectible_tile, &width, &height);
		collectible_tile = mlx_put_image_to_window(vars.mlx, vars.win, img_collectible, 0, 64);
		
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
