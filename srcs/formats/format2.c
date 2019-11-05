/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:36:24 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/05 18:11:55 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "formats.h"
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
	
}
