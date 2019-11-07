/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:21:01 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/07 11:58:36 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "buffer.h"

int		append_prefix(char *buffer, t_parse infos)
{
	char *prefix;

	if (infos.spec & HEX_MIN)
		prefix = HEX_PRE;
	else if (infos.spec & HEX_MA)
		prefix = HEX_MA_PRE;
	else
		prefix = "";
	return (str_buffer_append(buffer, prefix));
}
