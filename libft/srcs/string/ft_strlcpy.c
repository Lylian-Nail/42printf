/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:46:46 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:28:54 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "lft_string.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int i;
	int max;

	if (dst && src)
	{
		i = 0;
		max = dstsize - 1;
		while (src[i] && i < max)
		{
			dst[i] = src[i];
			i++;
		}
		if (dstsize > 0)
			dst[i] = '\0';
	}
	return (ft_strlen(src));
}
