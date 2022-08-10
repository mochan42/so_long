/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:18:41 by mochan            #+#    #+#             */
/*   Updated: 2022/08/10 22:59:40 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_empty_map(t_prgm *vars)
{
	if (vars->col == 0)
	{
		ft_printf("Map is missing some elements.\n");
		exit (0);
	}
}

void	check_rectangle(t_prgm *vars)
{
	int	j;

	j = 1;
	while (vars->map[j] != NULL)
	{
		if (ft_strlen_sl(vars->map[0]) != ft_strlen_sl(vars->map[j]))
		{
			ft_printf("Map is not rectangular or some elements are absent.\n");
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
			ft_printf("Map error : north wall has elements other than 1.\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (vars->map[last_row_idx][i] != '\0' && vars->map[0][i] != '\n')
	{
		if (vars->map[last_row_idx][i] != '1')
		{
			ft_printf("Map error : south wall has elements other than 1.\n");
			exit(0);
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
			ft_printf("Map error : west wall has elements other than 1.\n");
			exit(0);
		}
		j++;
	}
	j = 0;
	while (j < vars->row)
	{
		if (vars->map[j][last_col_idx] != '1')
		{
			ft_printf("Map error : east wall has elements other than 1.\n");
			exit(0);
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
		ft_printf("Map filename extension NOK : 3rd extension must be 'r'.\n");
		exit (0);
	}
	if (vars->map_path[--l] != 'e')
	{
		ft_printf("Map filename extension NOK : 2nd extension must be 'e'.\n");
		exit (0);
	}
	if (vars->map_path[--l] != 'b')
	{
		ft_printf("Map filename extension NOK : 1st extension must be 'b'.\n");
		exit (0);
	}
	if (vars->map_path[--l] != '.')
	{
		ft_printf("Map filename NOK : no file extension'.\n");
		exit (0);
	}
}
