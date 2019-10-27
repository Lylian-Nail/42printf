/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:58:54 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/09 13:57:48 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char		*memsrc;
	unsigned char		*memdst;

	if (dst && src)
	{
		memdst = dst;
		memsrc = (unsigned char*)src;
		while (len--)
			*memdst++ = *memsrc++;
	}
	return (dst);
}
