/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:31:32 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/11 12:04:44 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H

# define FORMATS_H

# include <stddef.h>
# include <stdarg.h>
# include "parse.h"

void		ft_fill(int c, size_t size);
void		append_sign(t_parse infos);
void		append_prefix(t_parse infos);
void		ft_putpadd_and_zeros(t_parse infos);
size_t		count_digits(long nbr, char *base);
void		ft_putnbr_base(unsigned long nbr, char *base);
void		ft_putnbr_base_sep(unsigned long long nbr,\
char *base, size_t c_digits);
void		format_char(t_parse *infos);
void		format_str(t_parse *infos, size_t len);
void		format_wide_str(t_parse *infos, size_t len);
void		format_nbr(t_parse *infos, size_t len, int is_printable);
void		format_base(t_parse *infos, size_t len, int is_printable);
void		output_char(char c, t_parse infos);
void		output_str(char *str, t_parse infos);
void		output_dec(long long nbr, t_parse infos);
void		output_uns(unsigned long long nb, t_parse infos);
void		output_base(unsigned long long n, t_parse i, char *base);
void		get_actual_len(int *ptr);
void		ft_format(char const *format, va_list args);

#endif
