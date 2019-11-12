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
	// CHAR
	printf("%d\n",
		ft_printf("This is the char:%c!\n", 'a'));
	printf("%d\n",
		printf("This is the char:%c!\n", 'a'));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%3c!\n", 'a'));
	printf("%d\n",
		printf("This is the char:%3c!\n", 'a'));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%-3c!\n", 'a'));
	printf("%d\n",
		printf("This is the char:%-3c!\n", 'a'));
	printf("\n");

	// UNDEFINED BEHAVIOR
	printf("%d\n",
		ft_printf("This is the char:%03c!\n", 'a'));
	printf("%d\n",
		printf("This is the char:%03c!\n", 'a'));
	printf("\n");

	// STR
	printf("%d\n",
		ft_printf("This is the char:%s!\n", "Hey you"));
	printf("%d\n",
		printf("This is the char:%s!\n", "Hey you"));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%3s!\n", "Hey you"));
	printf("%d\n",
		printf("This is the char:%3s!\n", "Hey you"));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%3.3s!\n", "Hey you"));
	printf("%d\n",
		printf("This is the char:%3.3s!\n", "Hey you"));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%3.s!\n", "Hey you"));
	printf("%d\n",
		printf("This is the char:%3.s!\n", "Hey you"));
	printf("\n");

	// NULL
	printf("%d\n",
		ft_printf("This is the char:%s!\n", NULL));
	printf("%d\n",
		printf("This is the char:%s!\n", NULL));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%300s!\n", NULL));
	printf("%d\n",
		printf("This is the char:%300s!\n", NULL));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%300.3s!\n", NULL));
	printf("%d\n",
		printf("This is the char:%300.3s!\n", NULL));
	printf("\n");

	// UNDEFINED BEHAVIOR
	printf("%d\n",
		ft_printf("This is the char:%300.3s!\n", NULL));
	printf("%d\n",
		printf("This is the char:%300.3s!\n", NULL));
	printf("\n");

	// SIGNED INT
	printf("%d\n",
		ft_printf("This is the char:%300d!\n", 100));
	printf("%d\n",
		printf("This is the char:%300d!\n", 100));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%300.30d!\n", 100));
	printf("%d\n",
		printf("This is the char:%300.30d!\n", 100));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%-300.30d!\n", 100));
	printf("%d\n",
		printf("This is the char:%-300.30d!\n", 100));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%030d!\n", 100));
	printf("%d\n",
		printf("This is the char:%030d!\n", 100));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%0300.30d!\n", 100));
	printf("%d\n",
		printf("This is the char:%0300.30d!\n", 100));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%0300.30d!\n", 100));
	printf("%d\n",
		printf("This is the char:%0300.30d!\n", 100));
	printf("\n");

	printf("%d\n",
		ft_printf("This is the char:%3.d!\n", 0));
	printf("%d\n",
		printf("This is the char:%3.d!\n", 0));
	printf("\n");
	return (0);
}
