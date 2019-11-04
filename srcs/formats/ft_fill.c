/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:31:00 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/29 17:48:29 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"

/*
**	desc: Fill the buffer with c until size reach 0.
**	args: #1 The buffer, #2 the char that we use to fill, #3 the num of items.
**	ret: Return the number of bytes writed to the output.
*/

int		ft_fill(char *buffer, int c, size_t size)
{
	int		bytes;

	bytes = 0;
	while (size--)
		bytes += buffer_append(buffer, c);
	return (bytes);
}
