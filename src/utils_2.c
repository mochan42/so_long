/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:10:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/12 13:40:16 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_map(t_prgm *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

void	free_all(t_prgm *vars)
{
	free_map(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_printf("exit so_long");
}

void	quit_prgm(t_prgm *vars)
{
	free_all(vars);
	exit (0);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*i2a(int nbr)
{
	char	*str;
	int		len;

	len = get_len(nbr);
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (nbr < 0)
		str[0] = '-';
	else if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		len--;
		str[len] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
