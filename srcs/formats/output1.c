/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:05:15 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/07 16:29:43 by lperson-         ###   ########.fr       */
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

int		output_str(char *buffer, char *str, t_parse infos)
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

int		output_dec(char *buffer, long long nbr, t_parse infos)
{
	int					bytes;
	unsigned long long	nb;

	bytes = 0;
	nb = (nbr < 0) ? -nbr : nbr;
	if (nbr < 0)
		infos.flag |= NEG;
	format_nbr(&infos, count_digits(nbr, B_DEC));
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		bytes += ft_fill(buffer, ' ', infos.padding);
	if (nbr < 0)
		bytes += buffer_append(buffer, '-');
	else if (infos.flag & SIGNED)
		bytes += buffer_append(buffer, '+');
	else if (infos.flag & INV_SIGN)
		bytes += buffer_append(buffer, ' ');
	if (infos.flag & PREC)
		bytes += ft_fill(buffer, '0', infos.prec);
	if (infos.flag & FILL_0)
		bytes += ft_fill(buffer, '0', infos.padding);
	bytes += ft_putnbr_base(buffer, nb, B_DEC);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}

int		output_uns(char *buf, unsigned long long nbr, t_parse infos)
{
	int				bytes;

	bytes = 0;
	format_nbr(&infos, count_digits(nbr, B_DEC));
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		bytes += ft_fill(buf, ' ', infos.padding);
	if (infos.flag & SIGNED)
		bytes += buffer_append(buf, '+');
	else if (infos.flag & INV_SIGN)
		bytes += buffer_append(buf, ' ');
	if (infos.flag & PREC)
		bytes += ft_fill(buf, '0', infos.prec);
	if (infos.flag & FILL_0)
		bytes += ft_fill(buf, '0', infos.padding);
	bytes += ft_putnbr_base(buf, nbr, B_DEC);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buf, ' ', infos.padding);
	return (bytes);
}

int		output_base(char *bu, unsigned long long nbr, t_parse i, char *ba)
{
	int		bytes;

	bytes = 0;
	format_base(&i, count_digits(nbr, ba));
	if (!(i.flag & LFT_PADD) && !(i.flag & FILL_0))
		bytes += ft_fill(bu, ' ', i.padding);
	if (i.flag & PREFIX)
		bytes += append_prefix(bu, i);
	if (i.flag & PREC)
		bytes += ft_fill(bu, '0', i.prec);
	if (i.flag & FILL_0)
		bytes += ft_fill(bu, '0', i.padding);
	bytes += ft_putnbr_base(bu, nbr, ba);
	if (i.flag & LFT_PADD)
		bytes += ft_fill(bu, ' ', i.padding);
	return (bytes);
}
