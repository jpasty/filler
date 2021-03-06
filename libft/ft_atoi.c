/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 18:23:21 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/01 10:00:48 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_atoi(const char *str)
{
	unsigned long int	res;
	int					sign;
	unsigned char		*s;

	res = 0;
	sign = 1;
	s = (unsigned char *)str;
	while (*s == ' ' || (*s > 8 && *s < 14))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580 &&
					(*s - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
						&& (*s - '0') > 8)) && sign == -1)
			return (0);
		res = res * 10 + *s - '0';
		s++;
	}
	return ((int)(res * sign));
}
