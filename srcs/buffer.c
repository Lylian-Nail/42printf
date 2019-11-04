/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:07:30 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/29 17:23:57 by lperson-         ###   ########.fr       */
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

	buffer[i++] = item;
	buffer[i] = 0;
	bytes = 0;
	if (i == BUFFER_SIZE)
	{
		bytes = buffer_clear(buffer);
		i = 0;
	}
	return (bytes);
}

/*
**	desc: Clear the buffer but write it to STD_OUT before it. Fill it.
**	with zeros and return the len that has been printed. Or -1 if error.
**	args: #1 The buffer to clear.
**	ret: The len that has been printed or -1 in case of error.
*/

int		buffer_clear(char *buffer)
{
	size_t	len;
	int		bytes;

	len = ft_strlen(buffer);
	bytes = write(1, buffer, len);
	ft_bzero(buffer, BUFFER_SIZE);
	return (bytes);
}
