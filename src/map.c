/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:53:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/06 16:41:28 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**store_map(t_prgm vars)
{
	int		fd;
	char	*line;
	int		row_index;

	vars.map = malloc(sizeof(char *) * (vars.row));
	row_index = 1;
	if (!vars.map)
		return (0);
	fd = open(vars.map_path, O_RDONLY);
	line = get_next_line(fd);
	vars.map[0] = line;
	while (line != NULL)
	{
		line = get_next_line(fd);
		vars.map[row_index] = line;
		row_index++;
	}
	close(fd);
	return (vars.map);
}

char	*choose_tile_path(char c)
{
	char	*tile_path;

	tile_path = NULL;
	if (c == '1')
		tile_path = "./images/wall_tile_64x64.xpm";
	else if (c == '0')
		tile_path = "./images/floor_tile_64x64.xpm";
	else if (c == 'P')
		tile_path = "./images/player_tile_64x64.xpm";
	else if (c == 'E')
		tile_path = "./images/exit_tile_64x64.xpm";
	else if (c == 'C')
		tile_path = "./images/collectible_tile_64x64.xpm";
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
	vars->map = store_map(*vars);
	put_map_to_window(vars);
}
