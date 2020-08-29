/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:33:36 by jpasty            #+#    #+#             */
/*   Updated: 2020/08/29 16:08:19 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "filler.h"

int				main(void)
{
    char				*line;
	static t_contest	cntst;

	line = NULL;
	freopen("111","r",stdin); // for debugging opportunity. Delete in future.
	if (gnl(STDIN_FILENO, &line) != 1 || define_user(&cntst, line) == EXIT_FAILURE)
	{
		free(line);
		return (-1);
	}
	while (1)
	{
		if (define_map(&cntst) == EXIT_FAILURE)
			break ;
	}
	free(line);
	return (0);
}