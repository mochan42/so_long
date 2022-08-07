/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/07 11:52:06 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(t_prgm *vr, char *s)
{
	vr->map_path = s;
	vr->col = count_nb_col(vr->map_path);
	vr->row = count_nb_row(vr->map_path);
	vr->mlx = mlx_init();
	vr->win = mlx_new_window(vr->mlx, vr->col * 64, vr->row * 64, "so_long");
}

int	main(int ac, char **av)
{	
	t_prgm	gme;

	if (ac != 2)
	{
		ft_printf("Error : number of arguments should be 1.\n");
		return (0);
	}
	init_game(&gme, av[1]);
	display_map_window(&gme);
	mlx_key_hook(gme.win, key_hook, &gme);
	mlx_hook(gme.win, 17, 0, ft_close_window, &gme);
	mlx_loop(gme.mlx);
	return (0);
}
