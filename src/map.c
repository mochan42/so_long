/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:53:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/05 23:14:09 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int count_nb_col(char *map_path)
{
	int		nb_col;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	nb_col = ft_strlen(line) - 1;
	close(fd);
	return (nb_col);
}

int count_nb_row(char *map_path)
{
	int		nb_row;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	nb_row = 0;
	while(line != NULL)
	{
		line = get_next_line(fd);
		nb_row++;
	}
	close(fd);
	return (nb_row);
}

char **store_map(char *map_path, int nb_row)
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
	while(line != NULL)
	{
		line = get_next_line(fd);
		map[row_index] = line;
		row_index++;
	}
	close(fd);
	return (map);
}

int	put_map_to_window(t_prgm *vars, char **map, int nb_col, int nb_row)
{
	int		j;
	int		i;
	char	*path_tile;
	void	*img;
	int		x;
	int		y;
	int		height;
	int		width;
	int		a = 5;
	
	
	height = 64;
	width = 64;
	j = 0;
	y = 0;
	while( j < nb_row)
	{
		i = 0;
		x = 0;
		while (i < nb_col)
		{
			if (map[j][i] == '1')
				path_tile = "./images/wall_tile_64x64.xpm";
			else if (map[j][i] == '0')
				path_tile = "./images/floor_tile_64x64.xpm";
			else if (map[j][i] == 'P')
				path_tile = "./images/player_tile_64x64.xpm";
			else if (map[j][i] == 'E')
				path_tile = "./images/exit_tile_64x64.xpm";
			else if (map[j][i] == 'C')
				path_tile = "./images/collectible_tile_64x64.xpm";
			img = mlx_xpm_file_to_image(vars->mlx, path_tile, &width, &height);
			mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
			x = x + width;
			i++;
		}
		j++;
		y = y + height;
	}
	return (a);
}

int	display_map_window(t_prgm *vars, char *map_path)
{
	int		nb_col;
	int		nb_row;
	char	**map;
	int		a = 5;
	
	nb_col = count_nb_col(map_path);
	nb_row = count_nb_row(map_path);
	map = store_map(map_path, nb_row);
	put_map_to_window(vars, map, nb_col, nb_row);
	return (a);
}