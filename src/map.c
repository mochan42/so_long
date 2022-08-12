/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:55:04 by moninechan        #+#    #+#             */
/*   Updated: 2022/08/12 20:05:32 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**store_map(t_prgm vars)
{
	int		fd;
	// char	*line;
	int		row_index;

	vars.map = malloc(sizeof(char *) * (vars.row));
	row_index = 0;
	if (!vars.map)
		return (0);
	fd = open(vars.map_path, O_RDONLY);
	// line = get_next_line(fd);
	// vars.map[0] = line;
	// while (line != NULL)
	while (row_index < vars.row)
	{
		// line = get_next_line(fd);
		// vars.map[row_index] = line;
		vars.map[row_index] = get_next_line(fd);
		// if (line == NULL)
		// 	break ;
		row_index++;
	}
	close(fd);
	return (vars.map);
}
