/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 13:28:47 by jpasty            #+#    #+#             */
/*   Updated: 2020/10/03 19:27:18 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_xy	*new_token_coord(int x, int y)
{
	t_xy	*new;

	if (!(new = ft_memalloc(sizeof(t_xy))))
		return (NULL);
	new->x = x;
	new->y = y;
	return (new);
}

static int	check_line(const char *line, int *stars, int wdth)
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
		if (gnl(fd, &line) != 1 ||
			(check_line(line, &(*tkn)->stars, (*tkn)->wdth) == -1))
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
	if (!((*tkn)->crd = ft_memalloc(sizeof(t_xy *) * (*tkn)->stars)))
		return (EXIT_FAILURE);
	while (i < (*tkn)->hght * (*tkn)->wdth && s <= (*tkn)->stars)
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
		return (NULL);
	return (tkn);
}

int 	put_token(t_contest *cntst, t_token *tkn)
{
	if (!tkn)
		return (EXIT_FAILURE);

	printf("\nToken is: \n");
	for (int j = 0; j < tkn->stars; j++)
			printf("{%i,%i}", tkn->crd[j]->y, tkn->crd[j]->x);
		printf("\n");
	return (EXIT_SUCCESS);
}
