/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:35:09 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/07 18:28:03 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parse.h"
#include "formats.h"
#include "buffer.h"
#include "lft_string.h"

int			output_ptr(char *buffer, void *ptr, t_parse infos)
{
	int				bytes;
	unsigned long	nbr;

	bytes = 0;
	nbr = (unsigned long)ptr;
	format_ptr(&infos, count_digits(nbr, B_HEXA_MI));
	if (!(infos.flag & LFT_PADD) && !(infos.flag & FILL_0))
		bytes += ft_fill(buffer, ' ', infos.padding);
	bytes += str_buffer_append(buffer, HEX_PRE);
	if (infos.flag & PREC)
		bytes += ft_fill(buffer, '0', infos.prec);
	if (infos.flag & FILL_0)
		bytes += ft_fill(buffer, '0', infos.padding);
	bytes += ft_putnbr_base(buffer, nbr, B_HEXA_MI);
	if (infos.flag & LFT_PADD)
		bytes += ft_fill(buffer, ' ', infos.padding);
	return (bytes);
}

void		get_actual_len(char *buffer, int *ptr)
{
	if (ptr)
		*ptr = ft_strlen(buffer);
}
