/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:31:32 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/07 17:55:41 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H

# define FORMATS_H

# include <stddef.h>
# include <stdarg.h>

void		format_char(t_parse *infos);
void		format_str(t_parse *infos, size_t len);
void		format_wide_str(t_parse *infos, size_t len);
void		format_nbr(t_parse *infos, size_t len);
void		format_ptr(t_parse *infos, size_t len);
void		format_base(t_parse *infos, size_t len);
int			ft_fill(char *buffer, int c, size_t size);
int			append_prefix(char *buffer, t_parse infos);
size_t		count_digits(long nbr, char *base);
int			ft_putnbr_base(char *buffer, unsigned long nbr, char *base);
int			output_char(char *buffer, char c, t_parse infos);
int			output_str(char *buffer, char *str, t_parse infos);
int			output_ptr(char *buffer, void *ptr, t_parse infos);
int			output_dec(char *buffer, long long nbr, t_parse infos);
int			output_uns(char *buf, unsigned long long nb, t_parse infos);
int			output_base(char *buf, unsigned long long n, t_parse i, char *base);
void		get_actual_len(char *buffer, int *ptr);
int			ft_format(char *buffer, char const *format, va_list args);

#endif
