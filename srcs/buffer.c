/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:07:30 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/10 11:34:29 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "libft.h"
#include <unistd.h>


/*
**	desc: Get the buffer struc.
**	args: None.
**	ret: Return the struc to the buffer.
*/

t_buf				*_get_buffer(void)
{
	static t_buf	buffer;

	return (&buffer);
}

/*
**	desc: Return the pos in the buffer.
**	args: None.
**	ret: Return the pos in the buffer.
*/

static int			*_get_index(void)
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

void				buffer_append(int item)
{
	t_buf	*buffer;
	int		*i;

	buffer = _get_buffer();
	i = _get_index();
	buffer->buf[(*i)++] = item;
	if (*i == BUFFER_SIZE)
	{
		*i = 0;
		buffer->size += write(1, buffer->buf, BUFFER_SIZE);
		ft_bzero(buffer, BUFFER_SIZE);
	}
}

/*
**	desc: Append string to buffer.
**	args: #1 The buffer, #2 The string that is append.
**	ret: Return the bytes writed to stdout.
*/

void				str_buffer_append(char *str)
{
	while (*str)
		buffer_append(*str++);
}

/*
**	desc: Flush the buffer and write all.
**	args: None.
**	ret: Return the total count writed.
*/

size_t				flush_buffer(void)
{
	t_buf	*buffer;
	int		*i;
	long	size;

	buffer = _get_buffer();
	i = _get_index();
	buffer->size += write(1, buffer->buf, *i);
	size = buffer->size;
	ft_bzero(buffer->buf, BUFFER_SIZE);
	*i = 0;
	buffer->size = 0;
	return (size);
}
