/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 11:44:42 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/10 11:31:32 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_countdigits(int n)
{
	unsigned int	nbr;
	size_t			count;

	nbr = (n < 0) ? -n : n;
	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	size_t			digits;
	unsigned int	nbr;
	char			*itoa;

	nbr = (n < 0) ? -n : n;
	digits = (n < 0) ? ft_countdigits(n) + 1 : ft_countdigits(n);
	if (!(itoa = (char*)malloc(sizeof(char) * (digits + 1))))
		return (NULL);
	itoa[digits] = '\0';
	while (digits--)
	{
		itoa[digits] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}
