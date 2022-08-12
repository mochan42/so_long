/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:53:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/12 20:11:47 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_exit(t_prgm *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->row)
	{
		i = 0;
		while (i < vars->col)
		{
			if (vars->map[j][i] == 'E')
				vars->exit_nb++;
			i++;
		}
		j++;
	}
	if (vars->exit_nb < 1)
	{
		ft_printf("Error\nNo exit was found (min : 1).\n");
		exit (0);
	}
}

void	check_player(t_prgm *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->row)
	{
		i = 0;
		while (i < vars->col)
		{
			if (vars->map[j][i] == 'P')
				vars->player_nb++;
			i++;
		}
		j++;
	}
	if (vars->player_nb != 1)
	{
		ft_printf("Error\nNo player or more than 1 player.\n");
		exit (0);
	}
}

void	check_collectible(t_prgm *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->row)
	{
		i = 0;
		while (i < vars->col)
		{
			if (vars->map[j][i] == 'C')
				vars->collect_nb++;
			i++;
		}
		j++;
	}
	if (vars->collect_nb < 1)
	{
		ft_printf("Error\nNo collectible was found (min : 1).\n");
		exit (0);
	}
}

void	check_valid_char(t_prgm *vars)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->row)
	{
		i = 0;
		while (i < vars->col)
		{
			if (!ft_strchr_sl("10CEP", vars->map[j][i]))
				vars->invalid_char++;
			i++;
		}
		j++;
	}
	if (vars->invalid_char > 0)
	{
		ft_printf("Error\nOnly authorized characters : 1, 0, C, E, P.\n");
		exit (0);
	}
}

void	check_map(t_prgm *vars)
{
	vars->map = store_map(*vars);
	check_empty_map(vars);
	check_rectangle(vars);
	check_valid_char(vars);
	check_exit(vars);
	check_player(vars);
	check_collectible(vars);
	check_ns_wall(vars);
	check_ew_wall(vars);
	check_map_file_extension(vars);
}
