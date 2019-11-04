/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:09:18 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/29 17:24:23 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H

# define BUFFER_H

# include <stddef.h>

# define BUFFER_SIZE	(64)

int		buffer_append(char *buffer, int item);
int		buffer_clear(char *buffer);

#endif
