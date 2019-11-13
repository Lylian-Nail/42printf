/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:47:17 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/13 10:33:06 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "lft_string.h"
#include "buffer.h"
#include "parse.h"
#include "formats.h"

/*
**	desc: Not man 3 printf, it's bullshit but use the microsoft docs instead.
**	args: #1 The format string, #2 a list of arguments.
**	ret: Return the number of bytes writed or -1 in case of error.
*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_buf	buffer;

	va_start(args, format);
	buffer.size = 0;
	while (*format && buffer.size != -1)
	{
		if (*format == '%')
		{
			ft_format(&buffer, ++format, args);
			format = advance_cursor(format);
			if (*format && (ft_strchr(SPEC, *format) || *format == '%'))
				format++;
		}
		else
			buffer_append(&buffer, *format++);
	}
	va_end(args);
	return (flush_buffer(&buffer));
}
