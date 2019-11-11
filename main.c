/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:34:07 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/11 17:22:25 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>


int		main(void)
{
	// // %
	// printf("%d\n",
	// ft_printf("This is the letter:%05%!\n"));
	// printf("%d\n",
	// printf("This is the letter:%05%!\n"));
	// // // CHAR.
	// printf("%d\n",
	// ft_printf("This is the letter:%02c!\n", 'a'));
	// printf("%d\n",
	// printf("This is the letter:%02c!\n", 'a'));
	// // STR.
	// printf("%d\n",
	// ft_printf("This is the letters:%4.2s!\n", NULL));
	// printf("%d\n",
	// printf("This is the letters:%4.2s!\n", NULL));
	// NBR.
	// printf("%d\n",
	// ft_printf("This is the number:% -30lli!\n", 0));
	// printf("%d\n",
	// printf("This is the number:% -30lli!\n", 0));
	// printf("%d\n",
	// 	ft_printf("%500d\n", 0));
	// printf("%d\n",
	// 	printf("%500d\n", 0));
	// HEXA.
	// printf("%d\n",
	// ft_printf("This is the number:%#-3x!\n", 0));
	// printf("%d\n",
	// printf("This is the number:%#-3x!\n", 0));
	// // PTR.
	// int		nbr = 255;
	// printf("%d\n",
	// ft_printf("This is the addr:%60p!\n", &nbr));
	// printf("%d\n",
	// printf("This is the addr:%60p!\n", &nbr));
	// //Nothing.
	// printf("%d\n",
	// ft_printf("This is the addr:%60p!\n", &nbr));
	// printf("%d\n",
	// printf("This is the addr:%60p!\n", &nbr));
	// //%
	// printf("%d\n",
	// ft_printf("This is the addr:%%!\n"));
	// printf("%d\n",
	// printf("This is the addr:%%!\n"));
	// printf("%d\n",
	// ft_printf("This is the addr:%n!\n", &nbr));
	// printf("N=%d\n", nbr);
	// printf("%d\n",
	// printf("This is the addr:%n!\n", &nbr));
	// printf("N=%d\n", nbr);
	// //'
	// printf("%d\n",
	// 	printf("Integer is %'d and %d\n", 12345678));
	// TST
	printf("%d\n",
		ft_printf("%o", 123));
	// return (0);
}
