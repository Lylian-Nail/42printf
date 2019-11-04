/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:34:07 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/04 16:06:47 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "buffer.h"
#include "parse.h"


int		main(void)
{
	// printf("%d\n", printf("Hey you %3d\n", 1000));
	// t_parse	infos = init_flags("-3d");
	// printf("Flag: %d\nPadding: %d", infos.flag, infos.padding);
	printf("%d\n",
	ft_printf("This is the letters:%03.s!\n", ""));
	printf("%d\n",
	printf("This is the letters:%03.s!\n", ""));
	return (0);
}
