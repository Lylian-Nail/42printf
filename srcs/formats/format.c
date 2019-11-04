/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:05:15 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/04 13:07:18 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parse.h"

int		ft_format(char const *format, va_list args)
{
	t_parse	infos;

	infos = init_flags(format, args);
	if 
}