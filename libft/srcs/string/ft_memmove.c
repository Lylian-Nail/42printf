/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 23:08:58 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/09 13:39:43 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char		*memsrc;
	unsigned char			*memdst;
	unsigned char			memtmp[len];
	unsigned int			i;

	if (dst && src)
	{
		i = len;
		memdst = dst;
		memsrc = (unsigned char *)src;
		while (len--)
			memtmp[len] = memsrc[len];
		while (i--)
			memdst[i] = memtmp[i];
	}
	return (dst);
}
