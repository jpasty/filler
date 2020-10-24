/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:03:31 by jpasty            #+#    #+#             */
/*   Updated: 2020/10/24 14:42:57 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_xy		min_reverse_coord(t_xy **crd)
{
	t_xy	min;
	int		i;
	int		x_min;
	int		y_min;

	i = 0;
	x_min = crd[i]->x;
	y_min = crd[i]->y;
	while (crd[i])
	{
		x_min = crd[i]->x < x_min ? crd[i]->x : x_min;
		y_min = crd[i]->y < y_min ? crd[i]->y : y_min;
		i++;
	}
	min.x = x_min * -1;
	min.y = y_min * -1;
	return (min);
}

t_xy		*new_token_coord(int x, int y)
{
	t_xy	*new;

	if (!(new = ft_memalloc(sizeof(t_xy))))
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}

int			check_line(const char *line, int *stars, int wdth)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			return (EXIT_FAILURE);
		if (line[i] == '*')
			(*stars)++;
		i++;
	}
	if (i != wdth)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			check_area_heat(t_contest *cntst, t_xy **crd, int x, int y)
{
	int		overlap;
	int		heat;
	int		y_bias;
	int		x_bias;
	int		i;

	overlap = 0;
	i = 0;
	while (crd[i])
	{
		y_bias = crd[i]->y + y;
		x_bias = crd[i]->x + x;
		if ()
		if (cntst->plat.cells[y_bias][x_bias]->cntnt != cntst->foe)
			heat = cntst->plat.cells[y_bias][x_bias]->heat;
		if (cntst->plat.cells[y_bias][x_bias]->cntnt == cntst->plr)
			overlap++;
		i++;
	}
	return (overlap == 1 ? heat : 0);
}
