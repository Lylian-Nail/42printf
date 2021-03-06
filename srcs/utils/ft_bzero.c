/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 22:57:16 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:10:44 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*memarea;

	if (s)
	{
		memarea = s;
		while (len--)
			*memarea++ = 0;
	}
}
