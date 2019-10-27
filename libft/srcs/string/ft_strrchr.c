/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 12:09:26 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:29:13 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char*)&s[len]);
		len--;
	}
	return (NULL);
}
