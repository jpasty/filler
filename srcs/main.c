/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:33:36 by jpasty            #+#    #+#             */
/*   Updated: 2020/07/13 17:33:42 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include "filler.h"

int         main(void)
{
    char    *line = NULL;
    int     fd = open("111", O_RDWR|O_CREAT, S_IRWXU);

   // ft_putendl_fd("this is string", fd);
    while (gnl(STDIN_FILENO, &line) == 1)
        ft_putendl_fd(line, fd);
    close(fd);
}