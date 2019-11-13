/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_func1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:45:05 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/13 10:32:09 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "parse.h"
#include "buffer.h"
#include "lft_string.h"

/*
**	desc: Append a sign to the buffer (-, + or ' ').
**	args: #1 The same buffer, #2 the infos wich sign to use.
**	ret: The number of bytes writed.
*/

void		append_sign(t_buf *buffer, t_parse infos)
{
	if (infos.flag & NEG)
		buffer_append(buffer, '-');
	else if (infos.flag & SIGNED)
		buffer_append(buffer, '+');
	else if (infos.flag & INV_SIGN)
		buffer_append(buffer, ' ');
}

/*
**	desc: Append a prefix into buffer.
**	Prefix are (0: octal, 0x: hexa in min, 0X: hexa in maj).
**	args: #1 The same buffer that we use, always..., #2 The infos for the
**	prefix.
**	ret: Return the number of bytes writed or -1 in case of errors (again).
*/

void		append_prefix(t_buf *buffer, t_parse infos)
{
	char *prefix;

	if (infos.spec & HEX_MIN || infos.spec & PTR)
		prefix = HEX_PRE;
	else if (infos.spec & HEX_MA)
		prefix = HEX_MA_PRE;
	else
		prefix = "";
	str_buffer_append(buffer, prefix);
}

/*
**	desc: Fill the buffer with c until size reach 0.
**	args: #1 The buffer, #2 the char that we use to fill, #3 the num of items.
**	ret: Return the number of bytes writed to the output.
*/

void		ft_fill(t_buf *buffer, int c, size_t size)
{
	while (size--)
		buffer_append(buffer, c);
}

/*
**	desc: Count the digits of the nbr encoded int the spec base.
**	args: #1 The number, #2 the base.
**	ret: The number of digits encoded int the spec base.
*/

size_t		count_digits(unsigned long long nbr, char *base)
{
	size_t			count;
	size_t			len;

	count = 0;
	len = ft_strlen(base);
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= len;
		count++;
	}
	return (count);
}

/*
**	desc: Write the number in the buffer recursively.
**	args: #1 The eternal buffer, #2 the nbr, #3 the base wich it'encoded.
**	ret: Return the number of bytes writed of -1 gnagnagna.
*/

void		ft_putnbr_base(t_buf *buffer, unsigned long long nbr, char *base)
{
	size_t	len;

	len = ft_strlen(base);
	if (nbr >= len)
	{
		ft_putnbr_base(buffer, nbr / len, base);
		ft_putnbr_base(buffer, nbr % len, base);
	}
	else
		buffer_append(buffer, base[nbr]);
}
