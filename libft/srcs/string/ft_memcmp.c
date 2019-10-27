/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:20:49 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/09 13:40:59 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*memarea1;
	unsigned char	*memarea2;

	if (s1 && s2)
	{
		memarea1 = (unsigned char*)s1;
		memarea2 = (unsigned char *)s2;
		while (len--)
		{
			if (*memarea1 != *memarea2)
				return (*memarea1 - *memarea2);
			memarea1++;
			memarea2++;
		}
	}
	return (0);
}
