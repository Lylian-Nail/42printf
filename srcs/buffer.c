/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:07:30 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/13 10:56:02 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "lft_string.h"
#include <unistd.h>

/*
**	desc: Return the pos in the buffer.
**	args: None.
**	ret: Return the pos in the buffer.
*/

static int			*get_index(void)
{
	static int	i;

	return (&i);
}

/*
**	desc: Append a char to the buffer, if the buffer is entirely fill
**	print the datas and return that has been printed.
**	args: #1 the buffer, #2 the item that is append.
**	ret: Return the numbers of bytes that has been write to STD_OUT.
*/

void				buffer_append(t_buf *buffer, int item)
{
	int		*i;
	int		ret;

	i = get_index();
	buffer->buf[(*i)++] = item;
	if (*i == BUFFER_SIZE && buffer->size != -1)
	{
		*i = 0;
		ret = write(1, buffer->buf, BUFFER_SIZE);
		buffer->size = (ret != -1) ? buffer->size + ret : -1;
		ft_bzero(buffer, BUFFER_SIZE);
	}
}

/*
**	desc: Append string to buffer.
**	args: #1 The buffer, #2 The string that is append.
**	ret: Return the bytes writed to stdout.
*/

void				str_buffer_append(t_buf *buffer, char *str)
{
	while (*str)
		buffer_append(buffer, *str++);
}

/*
**	desc: Flush the buffer and write all.
**	args: None.
**	ret: Return the total count writed.
*/

int					flush_buffer(t_buf *buffer)
{
	int		*i;
	long	size;

	i = get_index();
	size = write(1, buffer->buf, *i);
	if (size != -1)
		size = buffer->size + size;
	ft_bzero(buffer->buf, BUFFER_SIZE);
	*i = 0;
	buffer->size = 0;
	return (size);
}
