/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:05:56 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/08 00:07:24 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdarg.h>
#include "lft_ctype.h"
#include "lft_string.h"
#include "parse.h"

unsigned long long		ft_atoull(char const *str)
{
	unsigned long long		nbr;

	nbr = 0;
	while (ft_isdigit(*str))
		nbr = nbr * 10 + (*str++ - '0');
	return (nbr);
}

int						is_flag(int c)
{
	return (c && ft_strchr(FLAG, c));
}

size_t					get_padding(char const *nb, t_parse *infos, va_list lst)
{
	long long	nbr;

	nbr = (*nb == '*') ? va_arg(lst, int) : ft_atoull(nb);
	if (nbr < 0)
		infos->flag |= LFT_PADD;
	return ((nbr < 0) ? -nbr : nbr);
}

size_t					get_prec(char const *nb, t_parse *infos, va_list lst)
{
	long long	nbr;

	nbr = (*nb == '*') ? va_arg(lst, int) : ft_atoull(nb);
	if (nbr >= 0)
		infos->flag |= PREC;
	return (nbr < 0 ? 0 : nbr);
}

char					*skip_digits(char const *format)
{
	if (*format == '.')
		format++;
	if (*format == '*')
		format++;
	while (ft_isdigit(*format))
		format++;
	return ((char*)format);
}
