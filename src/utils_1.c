/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 23:30:23 by mochan            #+#    #+#             */
/*   Updated: 2022/08/12 21:20:07 by mochan           ###   ########.fr       */
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
	if (!line)
	{
		ft_printf("Error\nMap is empty!\n");
		exit (0);
	}
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

int	ft_strchr_sl(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	if (*s == c)
		return (1);
	else
		return (0);
}

// Need to not take into account the newline character because every line
// have a newline character except the last line.
int	ft_strlen_sl(char *s)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
	{
		len++;
		i++;
	}
	return (len);
}

int	get_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
