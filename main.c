/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:34:07 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/08 00:14:45 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>


int		main(void)
{
	// CHAR.
	printf("%d\n",
	ft_printf("This is the letter:%-2c!\n", 'a'));
	printf("%d\n",
	printf("This is the letter:%-2c!\n", 'a'));
	// STR.
	printf("Mine: %d\n",
	ft_printf("This is the letters:%4s!\n", NULL));
	printf("Official: %d\n",
	printf("This is the letters:%4s!\n", NULL));
	// NBR.
	printf("%d\n",
	ft_printf("This is the number:% -30lli!\n", LLONG_MIN));
	printf("%d\n",
	printf("This is the number:% -30lli!\n", LLONG_MIN));
	// HEXA.
	printf("%d\n",
	ft_printf("This is the number:%#-10.50llX!\n", LLONG_MAX));
	printf("%d\n",
	printf("This is the number:%#-10.50llX!\n", LLONG_MAX));
	// PTR.
	int		nbr = 255;
	printf("%d\n",
	ft_printf("This is the addr:%60p!\n", &nbr));
	printf("%d\n",
	printf("This is the addr:%60p!\n", &nbr));
	//Nothing.
	printf("%d\n",
	ft_printf("This is the addr:%60p!\n", &nbr));
	printf("%d\n",
	printf("This is the addr:%60p!\n", &nbr));
	//%
	printf("%d\n",
	ft_printf("This is the addr:%%!\n"));
	printf("%d\n",
	printf("This is the addr:%%!\n"));
	printf("%d\n",
	ft_printf("This is the addr:%n!\n", &nbr));
	printf("N=%d\n", nbr);
	printf("%d\n",
	printf("This is the addr:%n!\n", &nbr));
	printf("N=%d\n", nbr);

	return (0);
}
