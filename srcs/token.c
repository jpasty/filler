/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 13:28:47 by jpasty            #+#    #+#             */
/*   Updated: 2020/09/26 17:03:45 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
static int	check_line(const char *line, int wdth)
{
	int		i;
	int		stars;

	i = 0;
	stars = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '*')
			return (EXIT_FAILURE);
		if (line[i] == '*')
			stars++;
		i++;
	}
	if (i != wdth)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	validate_token(int fd, t_token *tkn, char ***shape)
{
	int 	h;
	int		;
	char	*line;

	h = 0;
	line = NULL;
	if (!(*shape = ft_memalloc(sizeof(char *) * (tkn->hght + 1))))
		return (EXIT_FAILURE);
	while (h < tkn->hght)
	{
		if (gnl(fd, &line) != 1 || check_line(line, tkn->wdth) != EXIT_SUCCESS)
		{
			free(line);
			return (EXIT_FAILURE);
		}
		*shape[h++] = line;
	}
	//вернуть количество токенов, если -1, 0 -> ошибка
	return (EXIT_SUCCESS);
}

static int	create_token(int fd, t_token **tkn)
{
	char	**shape;

	if (validate_token(fd, *tkn, &shape) != EXIT_SUCCESS)
		return (EXIT_FAILURE);

	ft_free_split(shape);
}

t_token		*token_define(int fd)
{
	t_token	*tkn;

	if (!(tkn = ft_memalloc(sizeof(t_token))))
		return (NULL);
	if (get_area_size(&(tkn->hght), &(tkn->wdth)) != EXIT_SUCCESS)
		return (NULL);
	if (create_token(fd, &tkn) != EXIT_SUCCESS)
		return (NULL);

		h++;
	}
	return (tkn);
}

int 	put_token(t_contest *cntst, t_token *tkn)
{
	if (!tkn)
		return (EXIT_FAILURE);

	printf("\nToken is: \n");
	for (int i = 0; i < tkn->hght; i++)
	{
		for (int j = 0; j < tkn->wdth; j++)
			printf("{%i,%i}", tkn->crd[i][j].y, tkn->crd[i][j].x);
		printf("\n");
	}
	return (EXIT_SUCCESS);
}
