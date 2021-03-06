/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 13:28:47 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/04 22:39:25 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void token_destroy(t_token *tkn)
{
	for (int i = 0; i < tkn->stars; i++)
		free(tkn->crd[i]);
	free(tkn->crd);
	free(tkn);
}

static int	validate_token(int fd, t_token **tkn, char ***shape)
{
	int 	h;
	char	*line;

	h = 0;
	line = NULL;
	(*tkn)->stars = 0;
	if (!(*shape = ft_memalloc(sizeof(char *) * ((*tkn)->hght + 1))))
		return (EXIT_FAILURE);
	while (h < (*tkn)->hght)
	{
		if (gnl(fd, &line) != 1)
			return (EXIT_FAILURE);
		if (check_line(line, &(*tkn)->stars, (*tkn)->wdth) != EXIT_SUCCESS)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		(*shape)[h++] = line;
	}
	return (EXIT_SUCCESS);
}

static int	create_token(int fd, t_token **tkn)
{
	char	**shape;
	int		w;
	int 	h;
	int		i;
	int 	s;

	i = 0;
	s = 0;
	if (validate_token(fd, tkn, &shape) != EXIT_SUCCESS)
	{
		ft_free_split(shape);
		return (EXIT_FAILURE);
	}
	if (!((*tkn)->crd = ft_memalloc(sizeof(t_xy *) * ((*tkn)->stars) + 1)))
		return (EXIT_FAILURE);
	while (i < (*tkn)->hght * (*tkn)->wdth && s < (*tkn)->stars)
	{
		h = i / (*tkn)->wdth;
		w = i % (*tkn)->wdth;
		if (shape[h][w] == '*')
			(*tkn)->crd[s++] = new_token_coord(w, h);
		i++;
	}
	ft_free_split(shape);
	return (EXIT_SUCCESS);
}

t_token		*token_define(int fd)
{
	t_token	*tkn;

	if (!(tkn = ft_memalloc(sizeof(t_token))))
		return (NULL);
	if (get_area_size(&(tkn->hght), &(tkn->wdth)) != EXIT_SUCCESS ||
			create_token(fd, &tkn) != EXIT_SUCCESS)
	{
		free(tkn);
		return (NULL);
	}
	return (tkn);
}

int	 		put_token(t_contest *cntst, t_token *tkn)
{
	t_cell	tkn_bound_point;
	int 	heat;
	int 	x;
	int 	y;

	if (!tkn)
		return (EXIT_FAILURE);
	tkn_bound_point = (t_cell){min_reverse_coord(tkn), -1, 0};
	y = tkn_bound_point.crd.y;
	while (y < cntst->plat.hght)
	{
		x = tkn_bound_point.crd.x;
		while (x < cntst->plat.wdth)
		{
			heat = check_area_heat(cntst, tkn, x,  y);
			tkn_bound_point = heat && (heat <= tkn_bound_point.heat
				|| tkn_bound_point.heat <= 0) ? (t_cell){(t_xy){x, y}, heat, 0}
				: tkn_bound_point;
			x++;
		}
		y++;
	}
	token_destroy(tkn);
	ft_printf("%i %i\n", tkn_bound_point.crd.y, tkn_bound_point.crd.x);
	return (EXIT_SUCCESS);
}
