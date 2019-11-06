/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:24 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/06 04:55:58 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "formats.h"
#include "buffer.h"
#include <stddef.h>
#include <unistd.h>

void	format_char(t_parse *infos)
{
	if (infos->padding > 0)
		infos->padding--;
}

void	format_str(t_parse *infos, size_t len)
{
	len = (infos->flag & PREC && infos->prec < len) ? infos->prec : len;
	infos->prec = len;
	infos->padding = (infos->padding > len) ? infos->padding - len : 0;
}

void	format_nbr(t_parse *infos, size_t len)
{
	size_t		total_len;

	infos->prec = (infos->prec > len) ? infos->prec - len : 0;
	total_len = infos->prec + len;
	if (infos->padding > total_len)
		infos->padding -= total_len;
	else
		infos->padding = 0;
	if (infos->flag & NEG && infos->padding)
		infos->padding--;
}

void	format_ptr(t_parse *infos, size_t len)
{
	size_t		total_len;

	infos->prec = (infos->prec > len) ? infos->prec - len : 0;
	total_len = infos->prec + len;
	if (infos->padding > total_len)
		infos->padding -= total_len;
	else
		infos->padding = 0;
	infos->padding = (infos->padding >= 2) ? infos->padding -= 2 : 0;
}

int		output_ptr(char *buffer, void *ptr, t_parse infos)
{
	int				bytes;
	unsigned long	nbr;

	bytes = 0;
	nbr = (unsigned long)ptr;
	format_ptr(&infos, count_digits(nbr, HEXA_MI));
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		bytes += ft_fill(buffer, ' ', infos.padding);
	bytes += buffer_append(buffer, '0');
	bytes += buffer_append(buffer, 'x');
	if (infos.flag & PREC)
		bytes += ft_fill(buffer, '0', infos.prec);
	if (infos.flag & FILL_0)
		bytes += ft_fill(buffer, '0', infos.padding);
	bytes += ft_putnbr_base(buffer, nbr, HEXA_MI);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}
