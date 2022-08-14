/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   villain_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:32:13 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 19:11:10 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_villain_pos(t_prgm *vr)
{
	if (vr->fc_located == 1 && vr->map[vr->fcym][vr->fcxm - 1] == '0'
		&& vr->map[vr->fcym + 1][vr->fcxm - 1] == '0')
	{
		vr->map[vr->fcym][vr->fcxm - 1] = 'V';
		vr->vxm = vr->fcxm - 1;
		vr->vym = vr->fcym;
		vr->vxw = vr->vxm * 64;
		vr->vyw = vr->vym * 64;
		vr->b_activate_vill = 1;
	}
}

void	find_villain(t_prgm *vr)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (ft_strchr(vr->map[j], 'V') == 0)
		j++;
	while (vr->map[j][i] != 'V')
		i++;
	vr->vxm = i;
	vr->vym = j;
	vr->vxw = i * 64;
	vr->vyw = j * 64;
}

int	ct_to_frame_3(int counter, int frames)
{
	return (counter / SPEED_3 % frames);
}

int	ct_to_frame_4(int counter, int frames)
{
	return (counter / SPEED_4 % frames);
}
