/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:18:52 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/04 14:50:11 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include <stdarg.h>

typedef struct	s_parse
{
	unsigned int	flag;
	unsigned int	spec;
	int				padding;
	int				prec;
}				t_parse;

typedef enum	e_spec
{
	CHAR = (1u << 0),
	STR = (1u << 1),
	PTR = (1u << 2),
	INT = (1u << 3),
	UINT = (1u << 4),
	HEX_MA = (1u << 5),
	HEX_MIN = (1u << 6),
}				t_spec;

typedef enum	e_flag
{
	FILL_0 = (1u << 0),
	PREC = (1u << 1),
}				t_flag;

t_parse		init_flags(char const *format, va_list args);
char		*advance_cursor(char const *format);

#endif
