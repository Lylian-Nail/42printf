
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperson- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 14:38:10 by lperson-          #+#    #+#              #
#    Updated: 2019/11/04 11:50:57 by lperson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf
TST = a.out

MAKE = make -s -C
RM = rm -f

AR = ar
ARFLAGS = -crs

CC = gcc
CFLAGS += -I $(LIBFT_INC) -I headers/
CFLAGS += -g

INC = ./

LIBFT = $(addprefix $(LIBFT_PATH), libft.a)
LIBFT_PATH = libft/
LIBFT_INC = libft/headers/

SRCS = 
SRCS_T = main.c srcs/buffer.c srcs/ft_printf.c srcs/parser.c srcs/formats/ft_fill.c srcs/formats/format.c

OBJS = $(SRCS:.c=.o)
OBJS_T = $(SRCS_T:.c=.o)

all: $(TST)

$(TST): $(SRCS_T) | $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS_T) -o $@ -L$(LIBFT_PATH) -lft

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(LIBFT):
	$(MAKE) $(LIBFT_PATH)

%.o: %.c | $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)