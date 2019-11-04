/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:47:17 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/04 11:50:40 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "lft_string.h"
#include "buffer.h"
#include "parse.h"

int	ft_printf(const char *format, ...)
{
	int		total_count;
	char	buffer[BUFFER_SIZE + 1];
	va_list	args;

	va_start(args, format);
	total_count = 0;
	while (*format)
	{
		// if (*format == '%')
		// {
		// 	total_count += ft_format(buffer, format, args);
		// }
		// else
			total_count += buffer_append(buffer, *format);
		format++;
	}
	total_count += buffer_clear(buffer);
	va_end(args);
	return (total_count);
}
