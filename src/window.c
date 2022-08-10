/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:16:05 by mochan            #+#    #+#             */
/*   Updated: 2022/08/10 15:30:22 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// ft_free mlx xpm file to image
int	ft_close_window(t_prgm *vars)
{
	free_map(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_printf("exit so_long");
	exit (0);
	return (0);
}

char	*choose_tile_path(char c)
{
	char	*tile_path;

	tile_path = NULL;
	if (c == '1')
		tile_path = "./images/xpm/wall_tile_64x64.xpm";
	else if (c == '0')
		tile_path = "./images/xpm/floor_tile_64x64.xpm";
	else if (c == 'P')
		tile_path = "./images/xpm/player_v2_right_tile_64x64.xpm";
	else if (c == 'E')
		tile_path = "./images/xpm/exit_v2_tile_64x64.xpm";
	else if (c == 'C')
		tile_path = "./images/xpm/collectible_v2_tile_64x64.xpm";
	return (tile_path);
}

// The variable for t_prgm is named "vr" which is a shortname for "vars".
// This is done due to norminette constrains (line < 80 characters).
void	put_map_to_window(t_prgm *vr)
{
	int		j;
	int		i;
	char	*path;
	int		x;
	int		y;

	j = 0;
	y = 0;
	while (j < vr->row)
	{
		i = 0;
		x = 0;
		while (i < vr->col)
		{
			path = choose_tile_path(vr->map[j][i]);
			vr->img = mlx_xpm_file_to_image(vr->mlx, path, vr->wid, vr->hei);
			mlx_put_image_to_window(vr->mlx, vr->win, vr->img, x, y);
			x = x + *vr->wid;
			i++;
		}
		j++;
		y = y + *vr->hei;
	}
	mlx_string_put(vr->mlx, vr->win, vr->mxw, vr->myw, vr->w, "MOVES : ");
	mlx_string_put(vr->mlx, vr->win, vr->mcxw, vr->myw, vr->w, i2a(vr->steps));
}

// Added the initialization for height and width of each tile in the function 
// display_map_window because of norminette constrains (each function must have
// less than 25 lines) These initializations originally took place in the
// function put map to window.
void	display_map_window(t_prgm *vars)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	vars->hei = &height;
	vars->wid = &width;
	put_map_to_window(vars);
}
