/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 15:30:54 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/01 09:57:15 by jpasty           ###   ########.ru       */
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
			return (EXIT_FAILURE);
		cells[height][w]->cntnt = row[w];
		w++;
	}
	return (EXIT_SUCCESS);
}

int		get_area_size(int *height, int *width)
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
		if ((*height = ft_atoi(split[1])) == 0 ||
				(*width = ft_atoi(split[2])) == 0)
			return (EXIT_FAILURE);
	}
	ft_free_split(split);
	return (EXIT_SUCCESS);
}

int 			map_define(t_contest *cntst)
{
	int			h;
	char		*line;

	h = 0;
	line = NULL;
	if (get_area_size(&(cntst->plat.hght), &(cntst->plat.wdth)) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	gnl(STDIN_FILENO, &line);
	free(line);
	if (!(cntst->plat.cells = malloc(sizeof(t_cell *)* (cntst->plat.hght + 1))))
		return (EXIT_FAILURE);
	while (h < cntst->plat.hght && gnl(STDIN_FILENO, &line) >= 0 && line)
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