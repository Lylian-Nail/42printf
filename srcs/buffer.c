/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:07:30 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/07 23:39:35 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "libft.h"
#include <unistd.h>

/*
**	desc: Append a char to the buffer, if the buffer is entirely fill
**	print the datas and return that has been printed.
**	args: #1 the buffer, #2 the item that is append.
**	ret: Return the numbers of bytes that has been write to STD_OUT.
*/

int		buffer_append(char *buffer, int item)
{
	static size_t	i;
	int				bytes;

	bytes = 0;
	if (item != 0)
		buffer[i++] = item;
	if (i == BUFFER_SIZE)
	{
		bytes += write(1, buffer, BUFFER_SIZE);
		i = 0;
		ft_bzero(buffer, BUFFER_SIZE);
	}
	else if (item == 0)
	{
		bytes += write(1, buffer, i);
		i = 0;
		ft_bzero(buffer, BUFFER_SIZE);
	}
	return (bytes);
}

/*
**	desc: Append string to buffer.
**	args: #1 The buffer, #2 The string that is append.
**	ret: Return the bytes writed to stdout.
*/

int		str_buffer_append(char *buffer, char *str)
{
	int			bytes;

	bytes = 0;
	while (*str)
		bytes += buffer_append(buffer, *str++);
	return (bytes);
}
