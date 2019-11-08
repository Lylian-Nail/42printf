/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:05:15 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/08 19:06:17 by lperson-         ###   ########.fr       */
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
	if (c)
		bytes += buffer_append(buffer, c);
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
		bytes += buffer_append(buffer, *s++);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, fill, infos.padding);
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
	format_nbr(&infos, count_digits(nb, B_DEC), nbr == 0);
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		bytes += ft_fill(buffer, ' ', infos.padding);
	if (infos.flag & NEG || infos.flag & SIGNED || infos.flag & INV_SIGN)
		bytes += append_sign(buffer, infos);
	if (infos.flag & PREC)
		bytes += ft_fill(buffer, '0', infos.prec);
	if (infos.flag & FILL_0)
		bytes += ft_fill(buffer, '0', infos.padding);
	if (nbr != 0 || (nbr == 0 && !(infos.flag & PREC)))
		bytes += ft_putnbr_base(buffer, nb, B_DEC);
	else if (nbr == 0 && infos.flag & PREC && infos.prec > 0)
		bytes += ft_putnbr_base(buffer, nb, B_DEC);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}

int		output_uns(char *buf, unsigned long long nbr, t_parse infos)
{
	int				bytes;

	bytes = 0;
	format_nbr(&infos, count_digits(nbr, B_DEC), nbr == 0);
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		bytes += ft_fill(buf, ' ', infos.padding);
	if (infos.flag & SIGNED || infos.flag & INV_SIGN)
		bytes += append_sign(buf, infos);
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
	if (nbr == 0)
		i.flag |= ZERO;
	format_base(&i, count_digits(nbr, ba));
	if (!(i.flag & LFT_PADD) && !(i.flag & FILL_0))
		bytes += ft_fill(bu, ' ', i.padding);
	if (i.flag & PREFIX)
		bytes += append_prefix(bu, i);
	if (i.flag & PREC)
		bytes += ft_fill(bu, '0', i.prec);
	if (i.flag & FILL_0)
		bytes += ft_fill(bu, '0', i.padding);
	if (!(i.flag & ZERO && i.flag & PREC && i.prec > 0))
		bytes += ft_putnbr_base(bu, nbr, ba);
	if (i.flag & LFT_PADD)
		bytes += ft_fill(bu, ' ', i.padding);
	return (bytes);
}
