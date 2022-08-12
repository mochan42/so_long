/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:18:41 by mochan            #+#    #+#             */
/*   Updated: 2022/08/12 20:08:14 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_empty_map(t_prgm *vars)
{
	if (vars->col == 0)
	{
		ft_printf("Error\nMap is missing some elements.\n");
		exit (0);
	}
}

void	check_rectangle(t_prgm *vars)
{
	int	j;

	j = 1;
	ft_printf("\n");
	ft_printf("vars->map[0] length is : %d\n", ft_strlen_sl(vars->map[0]));
	// while (vars->map[j] != NULL)
	while (j < vars->row)
	{
		ft_printf("vars->map[%d] length is : %d\n", j, ft_strlen_sl(vars->map[j]));
		if (ft_strlen_sl(vars->map[0]) != ft_strlen_sl(vars->map[j]))
		{
			ft_printf("Error\nMap not rectangular or some elements absent.\n");
			exit (0);
		}
		j++;
	}
}

void	check_ns_wall(t_prgm *vars)
{
	int	i;
	int	last_row_idx;

	i = 0;
	last_row_idx = vars->row - 1;
	while (vars->map[0][i] != '\0' && vars->map[0][i] != '\n')
	{
		if (vars->map[0][i] != '1')
		{
			ft_printf("Error\nNorth wall has elements other than 1.\n");
			exit (0);
		}
		i++;
	}
	i = 0;
	while (vars->map[last_row_idx][i] != '\0' && vars->map[0][i] != '\n')
	{
		if (vars->map[last_row_idx][i] != '1')
		{
			ft_printf("Error\nSouth wall has elements other than 1.\n");
			exit (0);
		}
		i++;
	}
}

void	check_ew_wall(t_prgm *vars)
{
	int	j;
	int	last_col_idx;

	j = 0;
	last_col_idx = vars->col - 1;
	while (j < vars->row)
	{
		if (vars->map[j][0] != '1')
		{
			ft_printf("Error\nWest wall has elements other than 1.\n");
			exit (0);
		}
		j++;
	}
	j = 0;
	while (j < vars->row)
	{
		if (vars->map[j][last_col_idx] != '1')
		{
			ft_printf("Error\nEast wall has elements other than 1.\n");
			exit (0);
		}
		j++;
	}
}

void	check_map_file_extension(t_prgm *vars)
{
	int	l;

	l = ft_strlen(vars->map_path);
	if (vars->map_path[--l] != 'r')
	{
		ft_printf("Error\nMap filename extension is incorrect.\n");
		exit (0);
	}
	else if (vars->map_path[--l] != 'e')
	{
		ft_printf("Error\nMap filename extension is incorrect.\n");
		exit (0);
	}
	else if (vars->map_path[--l] != 'b')
	{
		ft_printf("Error\nMap filename extension is incorrect.\n");
		exit (0);
	}
	else if (vars->map_path[--l] != '.')
	{
		ft_printf("Error\nMap filename extension is incorrect.\n");
		exit (0);
	}
}
