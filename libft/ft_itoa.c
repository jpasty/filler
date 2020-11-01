/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 17:05:08 by jpasty            #+#    #+#             */
/*   Updated: 2020/11/01 10:00:48 by jpasty           ###   ########.ru       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len(int n)
{
	size_t			len;
	unsigned int	nb;

	len = 0;
	if (n <= 0)
	{
		n *= -1;
		len++;
	}
	nb = (unsigned int)n;
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	size_t			i;

	i = ft_len(n);
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (i--)
	{
		str[i] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
