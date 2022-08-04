/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/05 00:22:13 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("exit so_long");
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
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
		void	*img;
		char	path_floor_tile[]="./images/floor_tile.xpm";
		int		floor_tile;
		
		int height;
		int width;
		
		vars.fd = open(av[1], O_RDONLY);
		height = 64;
		width = 64;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, 15*width, 11*height, "so_long");
		
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
