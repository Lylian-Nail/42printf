/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:01:11 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:10:34 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char		*memsrc;
	unsigned char		*memdst;
	unsigned char		c_mem;

	if (dst && src)
	{
		memdst = dst;
		c_mem = c;
		memsrc = (unsigned char*)src;
		while (len--)
		{
			*memdst = *memsrc++;
			if (*memdst++ == c_mem)
				return ((void*)memdst);
		}
	}
	return (NULL);
}
