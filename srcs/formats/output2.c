/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:35:09 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/08 16:15:02 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parse.h"
#include "formats.h"
#include "buffer.h"
#include "lft_string.h"

void		get_actual_len(char *buffer, int *ptr)
{
	if (ptr)
		*ptr = ft_strlen(buffer);
}
