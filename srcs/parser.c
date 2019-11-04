/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:58:43 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/04 16:06:13 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "lft_std.h"
#include "lft_string.h"
#include "lft_ctype.h"
#include "parse.h"
#include "buffer.h"
#include "formats.h"

/*
**	desc: Return the index of an item into an str.
**	args: #1 The str where we search the item, #2 The index to find.
**	ret: The index of the item in str.
*/

static size_t			get_index(char const *str, int item)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == item)
			return (index);
		index++;
	}
	return (index);
}

static int				is_flag(int c)
{
	char const *flag = "0-.*";

	return (c && ft_strchr(flag, c));
}

/*
**	desc:	Iter through the flags and get all the infos.
**	args:	#1 The char to parse, #2 the struct for the flags,
			#3 The list of args to get more infos.
**	ret:	Return the addr where the spec should be.
*/

static void			get_flags(char const *format, t_parse *info, va_list a)
{
	while (ft_isdigit(*format) || is_flag(*format))
	{
		if (*format == '0')
			info->flag |= FILL_0;
		if (*format == '*')
			info->prec = (int)va_arg(a, int);
		else if (ft_isdigit(*format) || *format == '-')
			info->padding = ft_atoi(format);
		else if (*format == '.')
		{
			info->prec = ft_atoi(format + 1);
			info->flag |= PREC;
		}
		if (*format == '.' || *format == '-' || ft_isdigit(*format))
		{
			if (*format == '-' || *format == '.')
				format++;
			while (ft_isdigit(*format))
				format++;
		}
		else
			format++;
	}
	if (info->spec < 0)
		info->flag ^= FILL_0;
}

/*
**	desc: Set the t_parse structure that contains all the infos for format the
**	output.
**	args: #1 The format string that we parse for gains the infos.
**	ret: Return the structure.
*/

t_parse				init_flags(char const *format, va_list args)
{
	const unsigned	tab[8] = {CHAR, STR, PTR, INT, INT, UINT, HEX_MA, HEX_MIN};
	const char		*convert = "cspiduxX";
	t_parse			infos;

	infos.spec = 0;
	infos.padding = 0;
	infos.flag = 0;
	get_flags(format, &infos, args);
	format = advance_cursor(format);
	if (ft_strchr(convert, *format))
		infos.spec |= tab[get_index(convert, *format)];
	return (infos);
}

char				*advance_cursor(char const *format)
{
	while (is_flag(*format))
		format++;
	while (ft_isdigit(*format))
		format++;
	while (is_flag(*format))
		format++;
	while (ft_isdigit(*format))
		format++;
	return ((char*)format);
}