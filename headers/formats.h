/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 17:31:32 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/05 16:17:40 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMATS_H

# define FORMATS_H

# include <stddef.h>
# include <stdarg.h>

unsigned long long	ft_atoull(char const *str);
void				format_char(t_parse *infos);
void				format_str(t_parse *infos, size_t len);
int					ft_fill(char *buffer, int c, size_t size);
size_t				count_digits(int nbr, char *base);
int					ft_putnbr_base(char *buffer, unsigned int nbr, char *base);
int					ft_format(char *buffer, char const *format, va_list args);

#endif
