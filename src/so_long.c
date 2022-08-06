/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/06 16:11:51 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{	
	t_prgm	gme;

	if (ac != 2)
	{
		ft_printf("Error : number of arguments should be 1.\n");
		return (0);
	}
	gme.map_path = av[1];
	gme.col = count_nb_col(gme.map_path);
	gme.row = count_nb_row(gme.map_path);
	gme.mlx = mlx_init();
	gme.win = mlx_new_window(gme.mlx, gme.col * 64, gme.row * 64, "so_long");
	display_map_window(&gme);
	mlx_key_hook(gme.win, key_hook, &gme);
	mlx_hook(gme.win, 17, 0, ft_close_window, &gme);
	mlx_loop(gme.mlx);
	return (0);
}
