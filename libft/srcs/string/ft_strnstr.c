/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 15:15:32 by lperson-          #+#    #+#             */
/*   Updated: 2019/10/09 14:05:05 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*match;
	char	*to_find;
	size_t	bytes;

	if (!needle || !haystack || !*needle)
		return ((!needle || !haystack) ? NULL : (char*)haystack);
	while (len && *haystack)
	{
		bytes = len--;
		if (*haystack == *needle)
		{
			to_find = (char*)needle;
			match = (char*)haystack++;
			while (bytes-- && *match == *to_find)
			{
				match++;
				to_find++;
				if (!*to_find)
					return ((char*)(haystack - 1));
			}
		}
		else
			haystack++;
	}
	return (NULL);
}
