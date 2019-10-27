/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:15:32 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:26:51 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lft_string.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, sizeof(char) * ft_strlen(s));
		write(fd, "\n", sizeof(char));
	}
}
