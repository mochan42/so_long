/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:10:21 by mochan            #+#    #+#             */
/*   Updated: 2022/08/13 17:27:01 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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

void	free_map(t_prgm *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		if (vars->map[i])
			free(vars->map[i]);
		i++;
	}
	if (vars->map)
		free(vars->map);
}

void	init_animation(t_prgm *vr)
{
	vr->path_img_1st_col = NULL;
	vr->path_img_plrr = NULL;
	vr->b_animate_fc = 1;
	vr->fc_located = 0;
	vr->fcxm = 0;
	vr->fcym = 0;
	vr->fcxw = 0;
	vr->fcyw = 0;
	vr->counter = 0;
	vr->b_right = 1;
	vr->b_left = 0;
	vr->path_img_vilr = NULL;
	vr->b_activate_vill = 0;
	vr->vxm = 0;
	vr->vym = 0;
	vr->vxw = 0;
	vr->vyw = 0;
	vr->b_v_right = 1;
	vr->b_v_left = 0;
}
