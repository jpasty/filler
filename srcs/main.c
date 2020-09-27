/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:33:36 by jpasty            #+#    #+#             */
/*   Updated: 2020/09/26 11:11:03 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "filler.h"

int				main(void)
{
    char				*line;
	static t_contest	cntst;

	line = NULL;
	freopen("../111","r",stdin); // for debugging opportunity. Delete in future.
	if (gnl(STDIN_FILENO, &line) != 1 || user_define(&cntst, line) != EXIT_SUCCESS)
	{
		free(line);
		return (-1);
	}
	while (1)
	{
		if (map_define(&cntst) != EXIT_SUCCESS)
			break ;
		heat_define(&cntst);
		if (put_token(&cntst, token_define(STDIN_FILENO)) != EXIT_SUCCESS)
			break ;
	}
	free(line);
	printf("%i %i", 0, 0);
	return (0);
}