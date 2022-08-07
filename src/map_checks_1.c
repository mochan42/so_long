/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moninechan <moninechan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 21:53:09 by mochan            #+#    #+#             */
/*   Updated: 2022/08/07 12:59:53 by moninechan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_exit(t_prgm *vars)
{
	int	i;
	int j;
	
	j = 0;
	while(j < vars->row)
	{
		i = 0;
		while( i < vars->col)
		{
			if(vars->map[j][i] == 'E')
				vars->exit_nb++;
			i++;	
		}
		j++;
	}
	if(vars->exit_nb < 1)
	{
		ft_printf("Map error : no exit was found.\n");
		exit (0);
	}
}

void	check_player(t_prgm *vars)
{
	int	i;
	int j;
	
	j = 0;
	while(j < vars->row)
	{
		i = 0;
		while( i < vars->col)
		{
			if(vars->map[j][i] == 'P')
				vars->player_nb++;
			i++;	
		}
		j++;
	}
	if(vars->player_nb < 1)
	{
		ft_printf("Map error : no player was found.\n");
		exit (0);
	}
}

void	check_collectible(t_prgm *vars)
{
	int	i;
	int j;
	
	j = 0;
	while(j < vars->row)
	{
		i = 0;
		while( i < vars->col)
		{
			if(vars->map[j][i] == 'C')
				vars->collect_nb++;
			i++;	
		}
		j++;
	}
	if(vars->collect_nb < 1)
	{
		ft_printf("Map error : no collectible was found.\n");
		exit (0);
	}
}

void	check_valid_char(t_prgm *vars)
{
	
}

void	check_map(t_prgm *vars)
{
	vars->map = store_map(*vars);
	check_valid_char(vars);
	check_exit(vars);
	check_player(vars);
	check_collectible(vars);
}
