/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:33:36 by jpasty            #+#    #+#             */
/*   Updated: 2020/08/22 17:30:37 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "filler.h"

int				main(void)
{
    char		*line = NULL;
	t_contest	cntst;

	freopen("111","r",stdin); // for debugging opportunity. Delete in future.
	if (gnl(STDIN_FILENO, &line) != 1 || define_user(line, &cntst))
	{
    	free(line);
    	return (1);
	}
	while (1)
	{
		define_map(&cntst, line);
		break ;
	}
	free(line);
	return (0);
}