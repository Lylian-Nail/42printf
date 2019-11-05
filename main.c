/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:34:07 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/05 17:45:24 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "buffer.h"
#include "parse.h"


int		main(void)
{
	// CHAR.
	// printf("%d\n",
	// ft_printf("This is the letter:%-2.c!\n", 'a'));
	// printf("%d\n",
	// printf("This is the letter:%-2.c!\n", 'a'));
	// STR.
	printf("Mine: %d\n",
	ft_printf("This is the letters:%*.*s!\n", -300, 1, "abc"));
	printf("Official: %d\n",
	printf("This is the letters:%*.*s!\n", -300, 1, "abc"));
	// NBR.
	// printf("%d\n",
	// ft_printf("This is the number:%04.-4d!\n", -255));
	// printf("%d\n",
	// printf("This is the number:%10.-10d!\n", -255));
	//HEXA.
	// printf("%d\n",
	// ft_printf("This is the number:%6.5x!\n", 255));
	// printf("%d\n",
	// printf("This is the number:%4.-5x!\n", 255));

	return (0);
}
