/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:45:05 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/06 03:35:13 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "buffer.h"
#include "lft_string.h"

size_t			count_digits(long nbr, char *base)
{
	size_t			count;
	unsigned long	nb;
	size_t			len;

	count = 0;
	nb = (nbr < 0) ? -nbr : nbr;
	len = ft_strlen(base);
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= len;
		count++;
	}
	return (count);
}

int				ft_putnbr_base(char *buffer, unsigned long nbr, char *base)
{
	int				bytes;
	size_t			len;

	len = ft_strlen(base);
	if (nbr > len)
	{
		bytes = ft_putnbr_base(buffer, nbr / len, base);
		return (ft_putnbr_base(buffer, nbr % len, base) + bytes);
	}
	else
		return (buffer_append(buffer, base[nbr]));
}
