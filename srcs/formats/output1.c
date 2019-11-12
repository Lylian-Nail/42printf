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

void	output_char(char c, t_parse infos)
{
	char	fill;

	format_char(&infos);
	fill = (infos.flag & FILL_0) ? '0' : ' ';
	if (!(infos.flag & LFT_PADD))
		ft_fill(fill, infos.padding);
	buffer_append(c);
	if (infos.flag & LFT_PADD)
		ft_fill(fill, infos.padding);
}

void	output_str(char *str, t_parse infos)
{
	char	fill;
	char	*s;

	s = (str) ? str : STR_NULL;
	format_str(&infos, ft_strlen(s));
	fill = (infos.flag & FILL_0) ? '0' : ' ';
	if (!(infos.flag & LFT_PADD))
		ft_fill(fill, infos.padding);
	while (infos.prec--)
		buffer_append(*s++);
	if (infos.flag & LFT_PADD)
		ft_fill(fill, infos.padding);
}

void	output_dec(long long nbr, t_parse infos)
{
	unsigned long long	nb;
	char				is_printable;

	nb = (nbr < 0) ? -nbr : nbr;
	is_printable = 1;
	if (nbr < 0)
		infos.flag |= NEG;
	if (nbr == 0 && infos.flag & PREC && infos.prec == 0)
		is_printable = 0;
	format_nbr(&infos, count_digits(nb, B_DEC), is_printable);
	ft_putpadd_and_zeros(infos);
	if (infos.flag & SEP && count_digits(nbr, B_DEC) > 3)
		ft_putnbr_base_sep(nbr, B_DEC, count_digits(nbr, B_DEC));
	else if (is_printable)
		ft_putnbr_base(nb, B_DEC);
	if (infos.flag & LFT_PADD)
		ft_fill(' ', infos.padding);
}

void	output_uns(unsigned long long nbr, t_parse infos)
{
	char	is_printable;

	is_printable = 1;
	if (nbr == 0 && infos.flag & PREC && infos.prec == 0)
		is_printable = 0;
	format_nbr(&infos, count_digits(nbr, B_DEC), is_printable);
	ft_putpadd_and_zeros(infos);
	if (infos.flag & SEP && count_digits(nbr, B_DEC) > 3)
		ft_putnbr_base_sep(nbr, B_DEC, count_digits(nbr, B_DEC));
	else if (is_printable)
		ft_putnbr_base(nbr, B_DEC);
	if (infos.flag & LFT_PADD)
		ft_fill(' ', infos.padding);
}

void	output_base(unsigned long long nbr, t_parse i, char *ba)
{
	char	is_printable;

	is_printable = 1;
	if (nbr == 0 && i.flag & PREC && i.prec == 0)
		is_printable = 0;
	if (nbr == 0 && i.flag & PREFIX && !(i.spec & PTR))
		i.flag ^= PREFIX;
	format_base(&i, count_digits(nbr, ba), is_printable);
	if (!(i.flag & LFT_PADD) && !(i.flag & FILL_0))
		ft_fill(' ', i.padding);
	if (i.flag & PREFIX)
		append_prefix(i);
	if (i.flag & PREC)
		ft_fill('0', i.prec);
	if (i.flag & FILL_0)
		ft_fill('0', i.padding);
	if (is_printable)
		ft_putnbr_base(nbr, ba);
	if (i.flag & LFT_PADD)
		ft_fill(' ', i.padding);
}
