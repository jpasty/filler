/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 13:28:47 by jpasty            #+#    #+#             */
/*   Updated: 2020/09/20 16:40:10 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	validate_token(int fd, t_token *tkn)
{
	char *line;
	int i;

	line = NULL;
	i = 0;
	if (gnl(fd, &line) != 1)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
		{
			free(line);
			return (EXIT_FAILURE);
		}
		i++;
	}
	free(line);
	if (i != tkn->wdth)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

t_token		*token_define(int fd)
{
	t_token	*tkn;
	int		h;
	int 	w;

	h = 0 ;
	if (!(tkn = ft_memalloc(sizeof(t_token))))
		return (NULL);
	if (get_area_size(&(tkn->hght), &(tkn->wdth)) != EXIT_SUCCESS)
		return (NULL);
	if (!(tkn->crd = malloc(sizeof(t_xy *) * tkn->hght)))
		return (NULL);
	while (tkn->crd[h] < tkn->hght)
	{
		w = 0;
		if (validate_token(fd, tkn) != EXIT_SUCCESS)
			return (NULL);
		if (!(tkn->crd[h] = ft_memalloc(sizeof(t_xy) * w)))
			return (NULL);
		while (w < tkn->wdth)
			tkn->crd[h][w] = (t_xy){h, w++};
		h++;
	}
	return (tkn);
}

int 	put_token(t_contest *cntst, t_token *tkn)
{
	if (!tkn)
		return (EXIT_FAILURE);

	return (EXIT_SUCCESS);
}
