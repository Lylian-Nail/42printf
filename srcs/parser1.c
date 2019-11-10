/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:58:43 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/10 17:23:09 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
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

static size_t		get_index(char const *str, int item)
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

/*
**	desc: Just get the infos of size_flag (ll, l, hh, h).
**	args: #1 The format string, #2 the infos to append.
**	ret: the new addr of format string.
*/

static char			*get_size_spec(char const *format, t_parse *infos)
{
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
			infos->mod_spec |= S_CHAR;
		else
			infos->mod_spec |= S_SHORT;
	}
	else if (*format == 'l')
	{
		if (*(format + 1) == 'l')
			infos->mod_spec |= S_LL;
		else
			infos->mod_spec |= S_LONG;
	}
	if (infos->mod_spec & S_LL || infos->flag & S_SHORT)
		return ((char*)(format + 1));
	return ((char*)format);
}

/*
**	desc:	Iter through the flags and get all the infos.
**	args:	#1 The char to parse, #2 the struct for the flags,
**			#3 The list of args to get more infos.
**	ret:	Return the addr where the spec should be.
*/

static void			get_flags(char const *format, t_parse *info, va_list lst)
{
	while (is_flag(*format) || ft_isdigit(*format))
	{
		if (*format == '0')
			info->flag |= FILL_0;
		else if (*format == '-')
			info->flag |= LFT_PADD;
		else if (*format == '.')
			info->prec = get_prec(format + 1, info, lst);
		else if (*format == '+')
			info->flag |= SIGNED;
		else if (*format == ' ')
			info->flag |= INV_SIGN;
		else if (*format == '#')
			info->flag |= PREFIX;
		else if (*format == '\'')
			info->flag |= SEP;
		else if (ft_isdigit(*format) || *format == '*')
			info->padding = get_padding(format, info, lst);
		else if (*format == 'h' || *format == 'l')
			format = get_size_spec(format, info);
		if ((ft_isdigit(*format) && *format != '0') || *format == '.')
			format = skip_digits(format);
		else
			format++;
	}
}

/*
**	desc: Set the t_parse structure that contains all the infos for format the
**	output.
**	args: #1 The format string that we parse for gains the infos.
**	ret: Return the structure.
*/

t_parse				init_flags(char const *format, va_list args)
{
	const unsigned	tab[10] = {\
	CHAR, STR, PTR, INT, INT, UINT, HEX_MIN, HEX_MA, LEN, FLOAT};
	t_parse			infos;

	infos.spec = 0;
	infos.padding = 0;
	infos.flag = 0;
	infos.prec = 0;
	infos.mod_spec = 0;
	get_flags(format, &infos, args);
	format = advance_cursor(format);
	if (ft_strchr(SPEC, *format))
		infos.spec |= tab[get_index(SPEC, *format)];
	if (infos.spec & PTR)
		infos.flag |= PREFIX;
	if (infos.flag & FILL_0 && (infos.flag & LFT_PADD || infos.flag & PREC))
		infos.flag ^= FILL_0;
	if (infos.flag & INV_SIGN && infos.flag & SIGNED)
		infos.flag ^= INV_SIGN;
	return (infos);
}

/*
**	desc: Advance the cursor to the spec.
**	args: #1 The format string.
**	ret: The addr of the spec in the string.
*/

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
	while (*format && ft_strchr("lh", *format))
		format++;
	return ((char*)format);
}
