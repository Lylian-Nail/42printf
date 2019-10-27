/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:25:31 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:29:19 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lft_string.h"

char			*ft_strtrim(char const *s, char const *set)
{
	size_t	trimlen;
	char	*strtrim;

	if (!s)
		return (NULL);
	while (*s && ft_strchr(set, *s))
		s++;
	trimlen = ft_strlen(s);
	while (trimlen && ft_strchr(set, s[trimlen - 1]))
		trimlen--;
	strtrim = (char*)malloc(sizeof(char) * (trimlen + 1));
	if (!strtrim)
		return (NULL);
	strtrim[trimlen] = '\0';
	return (ft_memcpy(strtrim, s, trimlen));
}
