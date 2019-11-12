/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:09:18 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/10 13:17:57 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H

# define BUFFER_H

# include <stddef.h>

# define BUFFER_SIZE	(256)

typedef struct	s_buf
{
	char		buf[BUFFER_SIZE];
	long		size;
}				t_buf;

t_buf	*_get_buffer(void);
void	buffer_append(int item);
void	str_buffer_append(char *str);
size_t	flush_buffer(void);

#endif
