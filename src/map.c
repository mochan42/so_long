/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:53:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/06 18:44:46 by mochan           ###   ########.fr       */
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
