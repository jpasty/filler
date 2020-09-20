/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:30:54 by jpasty            #+#    #+#             */
/*   Updated: 2020/09/12 22:13:27 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_content(t_cell **const *cells,
		char *row, int width, int height)
{
	int 		w;

	w = 0;
	if (!row || !cells[height])
		return (EXIT_FAILURE);
	while (w < width)
	{
		if (!(cells[height][w] = (t_cell *)malloc(sizeof(t_cell))))
			return (EXIT_FAILURE);
		cells[height][w]->crd.x = w;
		cells[height][w]->crd.y = height;
		row[w] = (char)ft_toupper(row[w]);
		if (row[w] != '.' && row[w] != 'O' && row[w] != 'X')
		{
			return (EXIT_FAILURE);
		}
		cells[height][w]->cntnt = row[w];
		cells[height][w]->heat = cells[height][w]->cntnt == '.' ?
				ft_abs(height + width) : 0;
		w++;
	}
	return (EXIT_SUCCESS);
}

static int		get_plateau_size(t_plateau *plt)
{
	char 		**split;
	char		*line;

	line = NULL;
	if (gnl(STDIN_FILENO, &line) != 1 || !(split = ft_strsplit(line, ' ')))
	{
		free(line);
		return (EXIT_FAILURE);
	}
	free(line);
	if (split[1] && split[2])
	{
		if ((plt->hght = ft_atoi(split[1])) == 0 ||
				(plt->wdth = ft_atoi(split[2])) == 0)
			return (EXIT_FAILURE);
	}
	ft_free_split(split);
	gnl(STDIN_FILENO, &line);
	free(line);
	return (EXIT_SUCCESS);
}

int 			map_define(t_contest *cntst)
{
	int			h;
	char		*line;

	h = 0;
	line = NULL;
	if (get_plateau_size(&(cntst->plat)) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (!(cntst->plat.cells = malloc(sizeof(t_cell *) * (cntst->plat.hght))))
		return (EXIT_FAILURE);
	while (h < cntst->plat.hght && gnl(STDIN_FILENO, &line) >= 0 && line
			&& !ft_strnequ(line, "Piece", 5))
	{
		cntst->plat.cells[h] =
				malloc(sizeof(t_cell *) * (cntst->plat.wdth));
		if (get_content(cntst->plat.cells, ft_strchr((line), ' ') + 1,
						cntst->plat.wdth, h) != EXIT_SUCCESS)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
		h++;
	}
	return (EXIT_SUCCESS);
}