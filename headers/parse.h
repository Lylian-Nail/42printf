/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:18:52 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/13 17:30:24 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H

# include <stdarg.h>
# include <stddef.h>

typedef struct		s_parse
{
	unsigned int	flag;
	unsigned int	spec;
	unsigned int	mod_spec;
	size_t			padding;
	size_t			prec;
}					t_parse;

typedef enum		e_spec
{
	CHAR = (1u << 0),
	STR = (1u << 1),
	PTR = (1u << 2),
	INT = (1u << 3),
	UINT = (1u << 4),
	HEX_MA = (1u << 5),
	HEX_MIN = (1u << 6),
	FLOAT = (1u << 7),
	LEN = (1u << 8),
}					t_spec;

typedef enum		e_mod_spec
{
	S_CHAR = (1u << 0),
	S_SHORT = (1u << 1),
	S_LONG = (1u << 2),
	S_LL = (1u << 3),
}					t_mod_spec;

typedef enum		e_flag
{
	FILL_0 = (1u << 0),
	LFT_PADD = (1u << 1),
	PREC = (1u << 2),
	NEG = (1u << 4),
	ZERO = (1u << 5),
	SIGNED = (1u << 6),
	INV_SIGN = (1u << 7),
	PREFIX = (1u << 8),
	SEP = (1u << 9),
}					t_flag;

# define FLAG		"0-.*# +lh'"
# define SPEC		"cspiduxXnf"

# define B_DEC 		"0123456789"
# define B_HEXA_MA	"0123456789ABCDEF"
# define B_HEXA_MI	"0123456789abcdef"
# define STR_NULL	"(null)"
# define HEX_PRE	"0x"
# define HEX_MA_PRE	"0X"

unsigned long long	ft_atoull(char const *str);
int					is_flag(int c);
size_t				get_padding(char const *nb, t_parse *infos, va_list lst);
size_t				get_prec(char const *nb, t_parse *infos, va_list lst);
t_parse				init_flags(char const *format, va_list args);
char				*advance_cursor(char const *format);
char				*skip_digits(char const *format);

#endif
