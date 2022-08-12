/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/13 00:55:50 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_game(t_prgm *vr, char *s)
{
	char	*title;

	title = "so_long";
	vr->map = NULL;
	vr->map_path = s;
	vr->col = count_nb_col(vr->map_path);
	vr->row = count_nb_row(vr->map_path);
	vr->mlx = mlx_init();
	vr->win = mlx_new_window(vr->mlx, vr->col * 64, (vr->row * 64) + 64, title);
	vr->exit_nb = 0;
	vr->player_nb = 0;
	vr->collect_nb = 0;
	vr->invalid_char = 0;
	vr->steps = 0;
	vr->mxw = ((64 * (vr->col)) / 2) - 64;
	vr->myw = (64 * vr->row) + 32;
	vr->mcxw = (64 * (vr->col)) / 2;
	vr->b = 0x00000000;
	vr->w = 0x00FFFFFF;
	init_animation(vr);
}

void	init_player_pos(t_prgm *vars)
{
	int	j;
	int	i;

	j = 0;
	while (j < vars->row)
	{
		i = 0;
		while (vars->map[j][i] != '\n' && vars->map[j][i] != '\0')
		{
			if (vars->map[j][i] == 'P')
			{
				vars->pxm = i;
				vars->pym = j;
			}
			i++;
		}
		j++;
	}
	vars->pxw = vars->pxm * 64;
	vars->pyw = vars->pym * 64;
}

void	init_moves_display(t_prgm *vr)
{
	char	*str;

	str = i2a(vr->steps);
	mlx_string_put(vr->mlx, vr->win, vr->mxw, vr->myw, vr->w, "MOVES :");
	mlx_string_put(vr->mlx, vr->win, vr->mcxw, vr->myw, vr->w, str);
	if (str)
		free(str);
}

int	ft_update(t_prgm *vr)
{
	animate_1st_collectible(vr);
	animate_player(vr);
	return (0);
}

int	main(int ac, char **av)
{	
	t_prgm		gme;

	if (ac != 2)
	{
		ft_printf("Error : number of arguments should be 1.\n");
		return (0);
	}
	init_game(&gme, av[1]);
	check_map(&gme);
	init_player_pos(&gme);
	find_1st_collectible(&gme);
	display_map_window(&gme);
	mlx_loop_hook(gme.mlx, ft_update, (void *)&gme);
	mlx_hook(gme.win, 17, 0, ft_close_window, &gme);
	mlx_key_hook(gme.win, key_hook, &gme);
	mlx_loop(gme.mlx);
	return (0);
}
