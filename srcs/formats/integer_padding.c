/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:35:50 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/05 15:00:49 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "formats.h"
#include "parse.h"
#include "buffer.h"

int		integer_padding(char *buffer, int nbr, size_t size, t_parse infos)
{
	int			bytes;
	size_t		padd;
	size_t		zeros;

	bytes = 0;
	size = (infos.prec > size) ? size + infos.prec : size;
	padd = (infos.padding < 0) ? -padd : padd;
	padd = (padd > size) ? size - padd : 0;
	zeros = (padd > 0 && infos.flag & FILL_0) ? padd : 0;
	zeros = (infos.prec >  ? 
	if (!(infos.flag & FILL_0) && padd > 0)
		bytes += ft_fill(buffer, ' ', padd);
	if (nbr < 0)
		bytes += buffer_append(buffer, '-');
	if (infos.flag & FILL_0 && zeros > 0)
		bytes += ft_fill(buffer, '0', zeros);
}