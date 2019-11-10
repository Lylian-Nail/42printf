/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:24 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/10 11:19:06 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include <stddef.h>
#include <unistd.h>

/*
**	I'm not going to details each functions, read the doc of printf to
**	understand the subtilities but each func modify the precisions and padding
**	to format the output.
*/

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

void	format_nbr(t_parse *infos, size_t len, int is_printable)
{
	size_t		pad_dec;

	if (infos->flag & PREC && infos->prec > len)
		infos->prec -= len;
	else
		infos->prec = 0;
	pad_dec = infos->prec + len;
	if (infos->flag & NEG || infos->flag & SIGNED || infos->flag & INV_SIGN)
		pad_dec += 1;
	if (!is_printable)
		pad_dec -= 1;
	infos->padding = (infos->padding > pad_dec) ? infos->padding - pad_dec : 0;
}

void	format_base(t_parse *infos, size_t len, int is_printable)
{
	size_t	pad_dec;

	if (infos->flag & PREC && infos->prec > len)
		infos->prec -= len;
	else
		infos->prec = 0;
	pad_dec = infos->prec + len;
	if (infos->flag & NEG || infos->flag & SIGNED || infos->flag & INV_SIGN)
		pad_dec += 1;
	if (infos->flag & PREFIX)
		pad_dec += 2;
	if (!is_printable)
		pad_dec -= 1;
	infos->padding = (infos->padding > pad_dec) ? infos->padding - pad_dec : 0;
}
