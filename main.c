/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:34:07 by lperson-          #+#    #+#             */
/*   Updated: 2019/11/04 11:52:28 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "buffer.h"
#include "parse.h"

static void print_parse(t_parse infos)
{
	printf("Padding: %d\n", infos.padding);
	if (infos.flag & FILL_0)
		printf("FILL WITH 0\n");
	else
		printf("FILL WITH SPACE\n");
	printf("Spec: %d\n", infos.spec);
	if (infos.spec & CHAR)
		printf("IS A CHAR\n");
	else if (infos.spec == 0)
		printf("HAS NO SPEC");
}

int		main(void)
{
	// printf("%d\n", printf("Hey you %3d\n", 1000));
	// t_parse	infos = init_flags("-3d");
	// printf("Flag: %d\nPadding: %d", infos.flag, infos.padding);
	printf("%0-30d", 5);
	
	return (0);
}
