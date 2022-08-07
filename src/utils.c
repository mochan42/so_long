/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:30:23 by mochan            #+#    #+#             */
/*   Updated: 2022/08/07 16:15:39 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	count_nb_col(char *map_path)
{
	int		nb_col;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	nb_col = ft_strlen(line) - 1;
	if (line)
		free(line);
	close(fd);
	return (nb_col);
}

int	count_nb_row(char *map_path)
{
	int		nb_row;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	line = get_next_line(fd);
	nb_row = 0;
	while (line != NULL)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
		nb_row++;
	}
	if (line)
		free(line);
	close(fd);
	return (nb_row);
}

void	free_all(t_prgm *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
}

int	ft_strchr_sl(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (*s == c)
		return (1);
	else
		return (0);
}