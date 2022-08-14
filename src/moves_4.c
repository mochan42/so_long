/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:18:25 by mochan            #+#    #+#             */
/*   Updated: 2022/08/14 16:27:07 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	collectible_handling_move_up(t_prgm *vr)
{
	vr->collect_nb--;
	vr->map[vr->pym - 1][vr->pxm] = '0';
	if (vr->pxm == vr->fcxw / 64 && vr->pym - 1 == vr->fcyw / 64)
			vr->b_animate_fc = 0;
}

void	collectible_handling_move_down(t_prgm *vr)
{
	vr->collect_nb--;
	vr->map[vr->pym + 1][vr->pxm] = '0';
	if (vr->pxm == vr->fcxw / 64 && vr->pym + 1 == vr->fcyw / 64)
		vr->b_animate_fc = 0;
}

void	collectible_handling_move_right(t_prgm *vr)
{
	vr->collect_nb--;
	vr->map[vr->pym][vr->pxm + 1] = '0';
	if (vr->pxm + 1 == vr->fcxw / 64 && vr->pym == vr->fcyw / 64)
		vr->b_animate_fc = 0;
}

void	collectible_handling_move_left(t_prgm *vr)
{
	vr->collect_nb--;
	vr->map[vr->pym][vr->pxm - 1] = '0';
	if (vr->pxm - 1 == vr->fcxw / 64 && vr->pym == vr->fcyw / 64)
		vr->b_animate_fc = 0;
}
