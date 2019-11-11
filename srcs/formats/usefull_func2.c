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

int	ft_putpadd_and_zeros(char *buffer, t_parse infos)
{
	int	bytes;

	bytes = 0;
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		bytes += ft_fill(buffer, ' ', infos.padding);
	if (infos.flag & NEG || infos.flag & SIGNED || infos.flag & INV_SIGN)
		bytes += append_sign(buffer, infos);
	if (infos.flag & PREC)
		bytes += ft_fill(buffer, '0', infos.prec);
	if (infos.flag & FILL_0)
		bytes += ft_fill(buffer, '0', infos.padding);
	return (bytes);
}

/*
**	desc: Putnbr with a separator ',' between each grouping numbers.
**	args: #1 The buffer, #2 the nbr, #3 The base wich is encoded, #4 the len\
**	the nbr.
**	ret: The number of bytes that has been writed.
*/

int	ft_putnbr_base_sep(char *buffer, unsigned long long nbr,\
char *base, size_t c_digits)
{
	int			bytes;
	size_t		len;
	long long	result;

	len = ft_strlen(base);
	bytes = 0;
	result = c_digits - count_digits(nbr, base);
	if (nbr >= len)
	{
		bytes = ft_putnbr_base_sep(buffer, nbr / len, base, c_digits);
		if ((c_digits - 1) % 3 == 0 && (result + 1) % 3 == 0)
			bytes += buffer_append(buffer, ',', 0);
		bytes += ft_putnbr_base_sep(buffer, nbr % len, base, c_digits);
		if ((c_digits - 1) % 3 != 0 && result && result % 3 == 0)
			bytes += buffer_append(buffer, ',', 0);
		return (bytes);
	}
	else
	{
		bytes += buffer_append(buffer, nbr + '0', 0);
		return (bytes);
	}
}
