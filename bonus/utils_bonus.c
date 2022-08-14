/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:35:23 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 18:35:44 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	vr->b_counter_vil_mot = 0;
}
