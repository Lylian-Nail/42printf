/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:16:18 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/09 13:40:34 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t len)
{
	unsigned char		*memarea;
	unsigned char		to_find;

	if (s)
	{
		to_find = c;
		memarea = (unsigned char*)s;
		while (len--)
		{
			if (*memarea == to_find)
				return ((void *)memarea);
			memarea++;
		}
	}
	return (NULL);
}
