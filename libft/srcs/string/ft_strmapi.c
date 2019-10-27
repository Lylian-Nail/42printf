/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:47:56 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/27 14:29:03 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lft_string.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*strmapi;

	if (!s)
		return (NULL);
	len = (int)ft_strlen(s);
	strmapi = (char*)malloc(sizeof(char) * (len + 1));
	if (!strmapi)
		return (NULL);
	strmapi[len] = '\0';
	while (len--)
		strmapi[len] = f(len, s[len]);
	return (strmapi);
}
