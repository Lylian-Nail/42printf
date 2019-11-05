/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:05:15 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/05 16:56:59 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "lft_string.h"
#include "parse.h"
#include "buffer.h"
#include "formats.h"

static int			output_char(char *buffer, int c, t_parse infos)
{
	int		bytes;

	bytes = 0;
	format_char(&infos);
	if (!(infos.flag & LFT_PADD))
		bytes += ft_fill(buffer, ' ', infos.padding);
	if (c)
		bytes += buffer_append(buffer, c);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}

static int			output_str(char *buffer, char *str, t_parse infos)
{
	int		bytes;

	bytes = 0;
	format_str(&infos, ft_strlen(str));
	if (!(infos.flag & LFT_PADD))
		bytes += ft_fill(buffer, ' ', infos.padding);
	while (infos.prec--)
		bytes += buffer_append(buffer, *str++);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}

static int			format_nbr(char *buffer, int nbr, t_parse infos, char *base)
{
	int		bytes;
	size_t	zeros;
	size_t	padd;
	size_t	size;

	bytes = 0;
	size = count_digits(nbr, base);
	zeros = (infos.prec > (int)size) ? infos.prec - size : 0;
	padd = (infos.padding < 0 ) ? -infos.padding : infos.padding;
	padd = padd - (zeros + size);
		padd = -infos.prec;
	if (!(infos.flag & FILL_0) && padd > 0)
		bytes += ft_fill(buffer, ' ', padd);
	if (nbr < 0)
		bytes += buffer_append(buffer, '-');
	if (infos.flag & FILL_0 || zeros > 0)
		bytes += ft_fill(buffer, '0', zeros);
	bytes += ft_putnbr_base(buffer, nbr < 0 ? -nbr : nbr, base);
	if (infos.padding < 0 || infos.prec < 0)
		bytes += ft_fill(buffer, ' ', padd);
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
		bytes += output_char(buffer, va_arg(args, int), infos);
	else if (infos.spec & STR)
		bytes += output_str(buffer, va_arg(args, char*), infos);
	else if (infos.spec & INT)
		bytes += format_nbr(buffer, va_arg(args, int), infos, DEC);
	else if (infos.spec & UINT)
		bytes += format_nbr(buffer, va_arg(args, unsigned int), infos, DEC);
	else if (infos.spec & HEX_MA)
		bytes += format_nbr(buffer, va_arg(args, unsigned int), infos, HEXA_MA);
	else if (infos.spec & HEX_MIN)
		bytes += format_nbr(buffer, va_arg(args, unsigned int), infos, HEXA_MI);
	return (bytes);
}
