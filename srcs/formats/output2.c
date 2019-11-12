/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:35:09 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/11 17:24:50 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "parse.h"
#include "formats.h"
#include "buffer.h"
#include "lft_string.h"

void		get_actual_len(int *ptr)
{
	if (ptr)
		*ptr = _get_buffer()->size;
}