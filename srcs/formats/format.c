/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:05:15 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/06 17:25:44 by lperson-         ###   ########.fr       */
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
	size_t	len;

	bytes = 0;
	len = (str || infos.flag & PREC) ? ft_strlen(str) : ft_strlen(STR_NULL);
	format_str(&infos, len);
	if (!(infos.flag & LFT_PADD))
		bytes += ft_fill(buffer, ' ', infos.padding);
	if (str == NULL && !(infos.flag & PREC))
		bytes += str_buffer_append(buffer, STR_NULL);
	while (str && infos.prec--)
		bytes += buffer_append(buffer, *str++);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}

static int			output_nbr(char *buffer, int nbr, t_parse infos, char *base)
{
	int				bytes;
	unsigned int	nb;

	bytes = 0;
	nb = (nbr < 0) ? -nbr : nbr;
	if (nbr < 0)
		infos.flag |= NEG;
	format_nbr(&infos, count_digits(nbr, base));
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		bytes += ft_fill(buffer, ' ', infos.padding);
	if (nbr < 0)
		bytes += buffer_append(buffer, '-');
	if (infos.flag & PREC)
		bytes += ft_fill(buffer, '0', infos.prec);
	if (infos.flag & FILL_0)
		bytes += ft_fill(buffer, '0', infos.padding);
	bytes += ft_putnbr_base(buffer, nb, base);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}

static int			output_uns(char *buf, unsigned n, t_parse inf, char *b)
{
	int				bytes;

	bytes = 0;
	format_nbr(&inf, count_digits(n, b));
	if (!(inf.flag & LFT_PADD) && !(inf.flag & FILL_0))
		bytes += ft_fill(buf, ' ', inf.padding);
	if (inf.flag & PREC)
		bytes += ft_fill(buf, '0', inf.prec);
	if (inf.flag & FILL_0)
		bytes += ft_fill(buf, '0', inf.padding);
	bytes += ft_putnbr_base(buf, n, b);
	if (inf.flag & LFT_PADD)
		bytes += ft_fill(buf, ' ', inf.padding);
	return (bytes);
}

/*
**	desc: Format the output and append it to buffer.
**	args: #1 the buffer we use, #2 The format string, #3 The list of args.
**	ret: The number of bytes writed.
*/

int					ft_format(char *buffer, char const *format, va_list args)
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
		bytes += output_nbr(buffer, va_arg(args, int), infos, DEC);
	else if (infos.spec & UINT)
		bytes += output_uns(buffer, va_arg(args, unsigned int), infos, DEC);
	else if (infos.spec & HEX_MA)
		bytes += output_uns(buffer, va_arg(args, unsigned int), infos, HEXA_MA);
	else if (infos.spec & HEX_MIN)
		bytes += output_uns(buffer, va_arg(args, unsigned int), infos, HEXA_MI);
	else if (infos.spec & PTR)
		bytes += output_ptr(buffer, va_arg(args, void*), infos);
	return (bytes);
}
