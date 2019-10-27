/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 01:18:00 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 13:10:32 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strnlen(char *dst, size_t maxlen)
{
	char *begin;

	if (!dst)
		return (0);
	begin = dst;
	while (maxlen-- && *dst)
		dst++;
	return (dst - begin);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		srclen;
	size_t		destlen;

	srclen = ft_strlen(src);
	destlen = ft_strnlen(dst, dstsize);
	dstsize -= destlen;
	if (!src || !dst || dstsize == 0)
		return (destlen + srclen);
	dst += destlen;
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (destlen + srclen);
}
