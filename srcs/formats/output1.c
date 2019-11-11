/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:05:15 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/11 16:29:45 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "lft_string.h"
#include "parse.h"
#include "buffer.h"
#include "formats.h"

int		output_char(char *buffer, char c, t_parse infos)
{
	int		bytes;
	char	fill;

	bytes = 0;
	format_char(&infos);
	fill = (infos.flag & FILL_0) ? '0' : ' ';
	if (!(infos.flag & LFT_PADD))
		bytes += ft_fill(buffer, fill, infos.padding);
	bytes += buffer_append(buffer, c, 0);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, fill, infos.padding);
	return (bytes);
}

int		output_str(char *buffer, char *str, t_parse infos)
{
	int		bytes;
	char	fill;
	char	*s;

	bytes = 0;
	s = (str) ? str : STR_NULL;
	format_str(&infos, ft_strlen(s));
	fill = (infos.flag & FILL_0) ? '0' : ' ';
	if (!(infos.flag & LFT_PADD))
		bytes += ft_fill(buffer, fill, infos.padding);
	while (infos.prec--)
		bytes += buffer_append(buffer, *s++, 0);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, fill, infos.padding);
	return (bytes);
}

int		output_dec(char *buffer, long long nbr, t_parse infos)
{
	int					bytes;
	unsigned long long	nb;
	char				is_printable;

	bytes = 0;
	nb = (nbr < 0) ? -nbr : nbr;
	is_printable = 1;
	if (nbr < 0)
		infos.flag |= NEG;
	if (nbr == 0 && infos.flag & PREC && infos.prec == 0)
		is_printable = 0;
	format_nbr(&infos, count_digits(nb, B_DEC), is_printable);
	bytes += ft_putpadd_and_zeros(buffer, infos);
	if (infos.flag & SEP && count_digits(nbr, B_DEC) > 3)
		bytes += ft_putnbr_base_sep(buffer, nbr, B_DEC,\
		count_digits(nbr, B_DEC));
	else if (is_printable)
		bytes += ft_putnbr_base(buffer, nb, B_DEC);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}

int		output_uns(char *buf, unsigned long long nbr, t_parse infos)
{
	int		bytes;
	char	is_printable;

	bytes = 0;
	is_printable = 1;
	if (nbr == 0 && infos.flag & PREC && infos.prec == 0)
		is_printable = 0;
	format_nbr(&infos, count_digits(nbr, B_DEC), is_printable);
	bytes += ft_putpadd_and_zeros(buf, infos);
	if (infos.flag & SEP && count_digits(nbr, B_DEC) > 3)
		bytes += ft_putnbr_base_sep(buf, nbr, B_DEC, count_digits(nbr, B_DEC));
	else if (is_printable)
		bytes += ft_putnbr_base(buf, nbr, B_DEC);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buf, ' ', infos.padding);
	return (bytes);
}

int		output_base(char *bu, unsigned long long nbr, t_parse i, char *ba)
{
	int		bytes;
	char	is_printable;

	bytes = 0;
	is_printable = 1;
	if (nbr == 0 && i.flag & PREC && i.prec == 0)
		is_printable = 0;
	if (nbr == 0 && i.flag & PREFIX && !(i.spec & PTR))
		i.flag ^= PREFIX;
	format_base(&i, count_digits(nbr, ba), is_printable);
	if (!(i.flag & LFT_PADD) && !(i.flag & FILL_0))
		bytes += ft_fill(bu, ' ', i.padding);
	if (i.flag & PREFIX)
		bytes += append_prefix(bu, i);
	if (i.flag & PREC)
		bytes += ft_fill(bu, '0', i.prec);
	if (i.flag & FILL_0)
		bytes += ft_fill(bu, '0', i.padding);
	if (is_printable)
		bytes += ft_putnbr_base(bu, nbr, ba);
	if (i.flag & LFT_PADD)
		bytes += ft_fill(bu, ' ', i.padding);
	return (bytes);
}
