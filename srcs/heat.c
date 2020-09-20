/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 09:41:31 by jpasty            #+#    #+#             */
/*   Updated: 2020/09/12 22:19:15 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

static int 	chebyshev_distance(t_xy end, t_xy start)
{
	int		dx = end.x - start.x;
	int 	dy = end.y - start.y;

	return ft_abs(dx) + ft_abs(dy);
//	return (ft_max(ft_abs(end.x - start.x),
//					ft_abs(end.y - start.y)));
}

static void	heat_cell_calc(t_contest *cntst, t_cell *cell)
{
	int		heat;
	int 	h;
	int 	w;

	h = 0;
	while (h < cntst->plat.hght)
	{
		w = 0;
		while (w < cntst->plat.wdth)
		{
			if (cntst->plat.cells[h][w]->cntnt == cntst->foe)
			{
				heat = chebyshev_distance(cell->crd, (t_xy){h, w});
				cell->heat = heat < cell->heat ? heat : cell->heat;
			}
			w++;
		}
		h++;
	}
}

void 		heat_define(t_contest *cntst)
{
	int		h;
	int 	w;

	h = 0;
	while (h < cntst->plat.hght)
	{
		w = 0;
		while (w < cntst->plat.wdth)
		{
			if (cntst->plat.cells[h][w]->cntnt == '.')
				heat_cell_calc(cntst, cntst->plat.cells[h][w]);
			w++;
		}
		h++;
	}
	for(int i = 0; i < cntst->plat.hght; i++)
	{
		for (int j = 0; j < cntst->plat.wdth; j++)
			printf("%2i ", cntst->plat.cells[i][j]->heat);
		printf("\n");
	}
}