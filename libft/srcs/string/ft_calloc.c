/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:23:06 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:10:39 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			bytes;
	unsigned char	*s;

	bytes = count * size;
	s = (unsigned char*)malloc(bytes);
	if (!s)
		return (NULL);
	while (bytes--)
		s[bytes] = 0;
	return ((void*)s);
}
