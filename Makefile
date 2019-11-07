
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

NAME = libftprintf.a
TST = a.out

MAKE = make -s -C
RM = rm -rf
MKDIR = mkdir -p

AR = ar
ARFLAGS = -crs

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I $(LIBFT_INC) -I headers/
CFLAGS += -g

INC = ./

LIBFT = $(addprefix $(LIBFT_PATH), libft.a)
LIBFT_PATH = libft/
LIBFT_INC = libft/headers/

BUILD = build/
PATHS = srcs/
PATHS_F = $(addprefix $(PATHS), formats/)


SRCS = $(addprefix $(PATHS), \
ft_printf.c \
buffer.c \
parser.c \
parser2.c)
SRCS += $(addprefix $(PATHS_F), \
usefull_func.c \
format.c \
format1.c \
output1.c \
output2.c)

OBJS = $(addprefix $(BUILD), $(notdir $(SRCS:.c=.o)))

.PHONY = all clean fclean re
all: $(NAME) $(TST)

$(NAME): $(BUILD) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(TST): $(NAME) $(LIBFT)
	$(CC) -g -I headers/ -I$(LIBFT_INC) main.c -L./ -lftprintf -Llibft/ -lft

$(LIBFT):
	$(MAKE) $(LIBFT_PATH)

$(BUILD):
	$(MKDIR) $(BUILD)

$(BUILD)%.o: $(PATHS)%.c | $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)%.o: $(PATHS_F)%.c | $(BUILD) $(LIBFT)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD) && $(MAKE) $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME) && $(MAKE) $(LIBFT_PATH) fclean

re: fclean all