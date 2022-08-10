/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/10 12:20:04 by mochan           ###   ########.fr       */
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
	vr->exit_nb = 0;
	vr->player_nb = 0;
	vr->collect_nb = 0;
	vr->invalid_char = 0;
	vr->steps = 0;
}

void	init_player_pos(t_prgm *vars)
{
	int	j;
	int	i;

	j = 0;
	while (vars->map[j] != NULL)
	{
		i = 0;
		while (vars->map[j][i] != '\n' && vars->map[j][i] != '\0')
		{
			if (vars->map[j][i] == 'P')
			{
				vars->pl_xm = i;
				vars->pl_ym = j;
			}
			i++;
		}
		j++;
	}
	vars->pl_xw = vars->pl_xm * 64;
	vars->pl_yw = vars->pl_ym * 64;
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
	check_map(&gme);
	init_player_pos(&gme);
	display_map_window(&gme);
	mlx_key_hook(gme.win, key_hook, &gme);
	mlx_hook(gme.win, 17, 0, ft_close_window, &gme);
	mlx_loop(gme.mlx);
	return (0);
}
