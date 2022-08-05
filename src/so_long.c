/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/06 00:33:50 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{	
	t_prgm	game;
	int		height;
	int		width;
	int		nb_col;
	int		nb_row;
	char	*map_path;

	if (ac == 2)
	{
		map_path = av[1];
		width = 64;
		height = 64;
		nb_col = count_nb_col(map_path);
		nb_row = count_nb_row(map_path);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, nb_col * width, nb_row * width, "so_long");
		display_map_window(&game, map_path);
		mlx_key_hook(game.win, key_hook, &game);
		mlx_hook(game.win, 17, 0, ft_close_window, &game);
		mlx_loop(game.mlx);
	}
	else
		ft_printf("One and only one argument string is required.\n");
	return (0);
}
