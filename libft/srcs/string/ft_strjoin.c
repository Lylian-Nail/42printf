/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:09:30 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:28:45 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	catlen;
	char	*strjoin;

	if (!s1 || !s2)
		return (NULL);
	catlen = ft_strlen(s1) + ft_strlen(s2);
	strjoin = (char*)malloc(sizeof(char) * (catlen + 1));
	if (!strjoin)
		return (NULL);
	strjoin[catlen] = '\0';
	while (*s1)
		*strjoin++ = *s1++;
	while (*s2)
		*strjoin++ = *s2++;
	return (strjoin - catlen);
}
