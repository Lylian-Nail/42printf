/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:44:18 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/13 10:36:51 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parse.h"
#include "formats.h"
#include "buffer.h"

/*
**	desc: Cast the arg into the spec type of an unsigned numbers.
**	Usefull for interpret ll hh h l flags.
**	args: #1 The list of args that we get, #2 The infos usefull for casting.
**	ret: Return the good casted value.
*/

unsigned long long	get_usize(va_list args, t_parse infos)
{
	if (infos.mod_spec & S_CHAR)
		return ((unsigned char)va_arg(args, int));
	else if (infos.mod_spec & S_SHORT)
		return ((unsigned short)va_arg(args, int));
	else if (infos.mod_spec & S_LONG)
		return (va_arg(args, unsigned long));
	else if (infos.mod_spec & S_LL || infos.spec & PTR)
		return (va_arg(args, unsigned long long));
	return (va_arg(args, unsigned int));
}

/*
**	desc: Cast the arg into the spec type of an signed numbers.
**	Usefull for interpret ll hh h l flags.
**	args: #1 The list of args that we get, #2 The infos usefull for casting.
**	ret: Return the good casted value.
*/

long long			get_size(va_list args, t_parse infos)
{
	if (infos.mod_spec & S_CHAR)
		return ((char)va_arg(args, int));
	else if (infos.mod_spec & S_SHORT)
		return ((short)va_arg(args, int));
	else if (infos.mod_spec & S_LONG)
		return (va_arg(args, long));
	else if (infos.mod_spec & S_LL)
		return (va_arg(args, long long));
	return (va_arg(args, int));
}

/*
**	desc: Format the output and append it to buffer.
**	args: #1 the buffer we use, #2 The format string, #3 The list of args.
**	ret: The number of bytes writed.
*/

void				ft_format(t_buf *buffer, char const *format, va_list args)
{
	t_parse	infos;

	infos = init_flags(format, args);
	format = advance_cursor(format);
	if (*format == '%')
		output_char(buffer, '%', infos);
	else if (infos.spec & CHAR)
		output_char(buffer, va_arg(args, int), infos);
	else if (infos.spec & STR)
		output_str(buffer, va_arg(args, char*), infos);
	else if (infos.spec & INT)
		output_dec(buffer, get_size(args, infos), infos);
	else if (infos.spec & UINT)
		output_uns(buffer, get_usize(args, infos), infos);
	else if (infos.spec & HEX_MA)
		output_base(buffer, get_usize(args, infos), infos, B_HEXA_MA);
	else if (infos.spec & HEX_MIN || infos.spec & PTR)
		output_base(buffer, get_usize(args, infos), infos, B_HEXA_MI);
	else if (infos.spec & LEN)
		get_actual_len(buffer, va_arg(args, void *));
}
