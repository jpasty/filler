/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpasty <jpasty@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 19:08:50 by jpasty            #+#    #+#             */
/*   Updated: 2020/06/21 19:08:50 by jpasty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*str;
	unsigned char		*res;
	size_t				i;

	if (dst == src)
		return (dst);
	res = (unsigned char *)dst;
	str = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
