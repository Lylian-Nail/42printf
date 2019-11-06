/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:18:52 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/06 17:18:15 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include <stdarg.h>
# include <stddef.h>

typedef struct	s_parse
{
	unsigned int	flag;
	unsigned int	spec;
	size_t			padding;
	size_t			prec;
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
	LFT_PADD = (1u << 1),
	PREC = (1u << 2),
	LFT_PREC = (1u << 3),
	NEG = (1u << 4),
}				t_flag;

# define DEC 		"0123456789"
# define HEXA_MA	"0123456789ABCDEF"
# define HEXA_MI	"0123456789abcdef"
# define STR_NULL	"(null)"

int				is_flag(int c);
size_t			get_padding(char const *nb, t_parse *infos, va_list lst);
size_t			get_prec(char const *nb, t_parse *infos, va_list lst);
t_parse			init_flags(char const *format, va_list args);
char			*advance_cursor(char const *format);
char			*skip_digits(char const *format);

#endif
