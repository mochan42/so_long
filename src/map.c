/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 12:55:04 by moninechan        #+#    #+#             */
/*   Updated: 2022/08/12 21:13:59 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**store_map(t_prgm vars)
{
	int		fd;
	int		row_index;

	row_index = 0;
	vars.map = malloc(sizeof(char *) * (vars.row));
	if (!vars.map)
		return (0);
	fd = open(vars.map_path, O_RDONLY);
	while (row_index < vars.row)
	{
		vars.map[row_index] = get_next_line(fd);
		row_index++;
	}
	close(fd);
	return (vars.map);
}
