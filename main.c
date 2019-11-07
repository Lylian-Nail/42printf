/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:34:07 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/07 18:40:24 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>


int		main(void)
{

	// ft_printf("Hey you%-10!\n", NULL);
	// printf("Hey you%-10!\n", NULL);
	// // CHAR.
	// printf("%d\n",
	// ft_printf("This is the letter:%-2.c!\n", 'a'));
	// printf("%d\n",
	// printf("This is the letter:%-2.c!\n", 'a'));
	// // STR.
	// printf("Mine: %d\n",
	// ft_printf("This is the letters:%4s!\n", NULL));
	// printf("Official: %d\n",
	// printf("This is the letters:%4s!\n", NULL));
	// // NBR.
	// printf("%d\n",
	// ft_printf("This is the number:%+-30lld!\n", INT_MAX));
	// printf("%d\n",
	// printf("This is the number:%+-30lld!\n", INT_MAX));
	// // HEXA.
	// printf("%d\n",
	// ft_printf("This is the number:%#-10.50llX!\n", LLONG_MAX));
	// printf("%d\n",
	// printf("This is the number:%#-10.50llX!\n", LLONG_MAX));
	// // PTR.
	int		nbr = 255;
	// printf("%d\n",
	// ft_printf("This is the addr:%060p!\n", NULL));
	// printf("%d\n",
	// printf("This is the addr:%060p!\n", NULL));
	// //Nothing.
	// printf("%d\n",
	// ft_printf("This is the addr:%60p!\n", &nbr));
	// printf("%d\n",
	// printf("This is the addr:%60p!\n", &nbr));
	// //%
	// printf("%d\n",
	// ft_printf("This is the addr:%%-60.30!\n", &nbr));
	// printf("%d\n",
	// printf("This is the addr:%%-60.30!\n", &nbr));
	//n
	printf("%d\n",
	ft_printf("This is the addr:%3n!\n", &nbr));
	printf("%N=%d\n", nbr);
	printf("%d\n",
	printf("This is the addr:%3n!\n", &nbr));
	printf("%N=%d\n", nbr);


	return (0);
}
