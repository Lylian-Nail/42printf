# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperson- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 14:38:10 by lperson-          #+#    #+#              #
#    Updated: 2019/11/13 09:53:12 by lperson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

MAKE = make -s -C
RM = rm -rf
MKDIR = mkdir -p

AR = ar
ARFLAGS = -crs # t'es crs ? Tro drol.

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I headers/
CFLAGS += -g

INC = ./

BUILD = build/
PATHS = srcs/
PATHS_F = $(addprefix $(PATHS), formats/)
PATHS_U = $(addprefix $(PATHS), utils/)

SRCS = $(addprefix $(PATHS), \
ft_printf.c \
buffer.c \
parser1.c \
parser2.c)
SRCS += $(addprefix $(PATHS_F), \
usefull_func1.c \
usefull_func2.c \
format1.c \
format2.c \
output1.c \
output2.c)
SRCS += $(addprefix $(PATHS_U), \
ft_bzero.c \
ft_isdigit.c \
ft_strchr.c \
ft_strlen.c)

OBJS = $(addprefix $(BUILD), $(notdir $(SRCS:.c=.o)))

.PHONY = all clean fclean re
all: $(NAME)

$(NAME): $(BUILD) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(BUILD):
	$(MKDIR) $(BUILD)

$(BUILD)%.o: $(PATHS)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)%.o: $(PATHS_F)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)%.o: $(PATHS_U)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BUILD)

fclean: clean
	$(RM) $(NAME)

bonus: re 

re: fclean all
