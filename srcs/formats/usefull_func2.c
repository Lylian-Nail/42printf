/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:21:05 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/11 12:05:29 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_string.h"
#include "buffer.h"
#include "formats.h"
#include "parse.h"

/*
**	desc: Put padd and zeros from infos.
**	args: #1 The buffer, #2 The infos.
**	ret: The number of bytes writed.
*/

void	ft_putpadd_and_zeros(t_parse infos)
{
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		ft_fill(' ', infos.padding);
	if (infos.flag & NEG || infos.flag & SIGNED || infos.flag & INV_SIGN)
		append_sign(infos);
	if (infos.flag & PREC)
		ft_fill('0', infos.prec);
	if (infos.flag & FILL_0)
		ft_fill('0', infos.padding);
}

/*
**	desc: Putnbr with a separator ',' between each grouping numbers.
**	args: #1 The buffer, #2 the nbr, #3 The base wich is encoded, #4 the len\
**	the nbr.
**	ret: The number of bytes that has been writed.
*/

void	ft_putnbr_base_sep(unsigned long long nbr,\
char *base, size_t c_digits)
{
	size_t		len;
	long long	result;

	len = ft_strlen(base);
	result = c_digits - count_digits(nbr, base);
	if (nbr >= len)
	{
		ft_putnbr_base_sep(nbr / len, base, c_digits);
		if ((c_digits - 1) % 3 == 0 && (result + 1) % 3 == 0)
			buffer_append(',');
		ft_putnbr_base_sep(nbr % len, base, c_digits);
		if ((c_digits - 1) % 3 != 0 && result && result % 3 == 0)
			buffer_append(',');
	}
	else
		buffer_append(nbr + '0');
}
