/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:05:15 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/04 15:45:02 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "lft_string.h"
#include "parse.h"
#include "buffer.h"
#include "formats.h"

static int		format_char(char *buffer, int c, t_parse infos)
{
	int				bytes;
	unsigned int	count;

	bytes = 0;
	count = (infos.padding < 0) ? -infos.padding - 1: infos.padding - 1;
	if (infos.padding > 0)
		bytes += ft_fill(buffer, ' ', count);
	if (c)
		bytes += buffer_append(buffer, c);
	if (infos.padding < 0)
		bytes += ft_fill(buffer, ' ', count);
	return (bytes);
}

static int		format_str(char *buffer, char *str, t_parse infos)
{
	int				bytes;
	int				max;
	unsigned int	count;
	size_t			len;

	bytes = 0;
	len = ft_strlen(str);
	max = (infos.flag & PREC) ? infos.prec : len;
	if (max > len)
		max = len;
	count = (infos.padding < 0) ? -infos.padding - max : infos.padding - max;
	if (infos.padding > 0)
		bytes += ft_fill(buffer, ' ', count);
	while (max--)
		bytes += buffer_append(buffer, *str++);
	if (infos.padding < 0)
		bytes += ft_fill(buffer, ' ', count);
	return (bytes);
}

/*
**	desc: Format the output and append it to buffer.
**	args: #1 the buffer we use, #2 The format string, #3 The list of args.
**	ret: The number of bytes writed.
*/

int				ft_format(char *buffer, char const *format, va_list args)
{
	t_parse	infos;
	int		bytes;

	bytes = 0;
	infos = init_flags(format, args);
	if (*format == '%')
		bytes += buffer_append(buffer, '%');
	if (infos.spec & CHAR)
		bytes += format_char(buffer, va_arg(args, int), infos);
	else if (infos.spec & STR)
		bytes += format_str(buffer, va_arg(args, char*), infos);
	return (bytes);
}