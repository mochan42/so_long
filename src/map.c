/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:53:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/06 00:30:15 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**store_map(char *map_path, int nb_row)
{
	char	**map;
	int		fd;
	char	*line;
	int		row_index;

	map = malloc(sizeof(char *) * (nb_row));
	row_index = 1;
	if (!map)
		return (0);
	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	map[0] = line;
	while (line != NULL)
	{
		line = get_next_line(fd);
		map[row_index] = line;
		row_index++;
	}
	close(fd);
	return (map);
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

void	put_map_to_window(t_prgm *vars, char **map, int nb_col, int nb_row)
{
	int		j;
	int		i;
	char	*tile_path;
	void	*img;
	int		x;
	int		y;
	int		height;
	int		width;

	height = 64;
	width = 64;
	j = 0;
	y = 0;
	while (j < nb_row)
	{
		i = 0;
		x = 0;
		while (i < nb_col)
		{
			tile_path = choose_tile_path(map[j][i]);
			img = mlx_xpm_file_to_image(vars->mlx, tile_path, &width, &height);
			mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
			x = x + width;
			i++;
		}
		j++;
		y = y + height;
	}
}

void	display_map_window(t_prgm *vars, char *map_path)
{
	int		nb_col;
	int		nb_row;
	char	**map;

	nb_col = count_nb_col(map_path);
	nb_row = count_nb_row(map_path);
	map = store_map(map_path, nb_row);
	put_map_to_window(vars, map, nb_col, nb_row);
}
