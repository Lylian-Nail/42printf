/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:34:07 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/06 17:29:43 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>


int		main(void)
{
	// CHAR.
	// printf("%d\n",
	// ft_printf("This is the letter:%-2.c!\n", 'a'));
	// printf("%d\n",
	// printf("This is the letter:%-2.c!\n", 'a'));
	// // STR.
	// printf("Mine: %d\n",
	// ft_printf("This is the letters:%4.s!\n", NULL));
	// printf("Official: %d\n",
	// printf("This is the letters:%4.s!\n", NULL));
	// NBR.
	printf("%d\n",
	ft_printf("This is the number:%3.10d!\n", 0));
	printf("%d\n",
	printf("This is the number:%3.10d!\n", 0));
	// // HEXA.
	// printf("%d\n",
	// ft_printf("This is the number:%06.5x!\n", 255));
	// printf("%d\n",
	// printf("This is the number:%06.5x!\n", 255));
	// // PTR.
	int		nbr = 255;
	printf("%d\n",
	ft_printf("This is the addr:%-60p!\n", NULL));
	printf("%d\n",
	printf("This is the addr:%-60p!\n", NULL));
	// //Nothing.
	// printf("%d\n",
	// ft_printf("This is the addr:%-60.30!\n", &nbr));
	// printf("%d\n",
	// printf("This is the addr:%-60.30!\n", &nbr));
	// //%
	// printf("%d\n",
	// ft_printf("This is the addr:%%-60.30!\n", &nbr));
	// printf("%d\n",
	// printf("This is the addr:%%-60.30!\n", &nbr));

	return (0);
}
