/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 15:14:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/05 21:34:55 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{	
	if(ac == 2)
	{
		t_prgm	vars;
		int		fd;
		int		height;
		int		width;
		char	*path_tile;
		int		nb_col;
		void	*img;
		char	*line;
		char	**map;
		int		nb_row;
		int		row_index;
		int		i;
		int		j;
		int		x;
		int		y;

		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		nb_col = ft_strlen(line) - 1;
		nb_row = 0;
		row_index = 1;
		while(line != NULL)
		{
			line = get_next_line(fd);
			nb_row++;
		}
		close(fd);
		ft_printf("nb of column is : %d\n", nb_col);
		ft_printf("nb of rows is : %d\n", nb_row);
		map = malloc(sizeof(char *) * (nb_row + 1));
		vars.tab = map;
		if (!map)
			return (0);
		fd = open(av[1], O_RDONLY);
		line = get_next_line(fd);
		map[0] = line;
		while(line != NULL)
		{
			line = get_next_line(fd);
			map[row_index] = line;
			ft_printf("%s", line);
			row_index++;
		}
		width = 64;
		height = 64;
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, nb_col*width, (row_index - 1)*height, "so_long");
		printf("row_index is : %d\n", row_index);
		j = 0;
		while( j < nb_row)
		{
			i = 0;
			x = 0;
			while (map[j][i] != '\n' && map[j][i] != '\0')
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
				img = mlx_xpm_file_to_image(vars.mlx, path_tile, &width, &height);
				mlx_put_image_to_window(vars.mlx, vars.win, img, x, y);
				x = x + width;
				i++;
			}
			j++;
			y = y + height;
		}
		mlx_key_hook(vars.win, key_hook, &vars);
		mlx_hook(vars.win, 17, 0, ft_close_window, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
