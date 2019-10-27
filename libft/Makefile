# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperson- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 13:35:26 by lperson-          #+#    #+#              #
#    Updated: 2019/10/27 13:09:48 by lperson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I$(INCLUDE)

AR = ar
ARFLAGS = -crs

RM = rm -rf
MKDIR = mkdir -p

INCLUDE = headers/
HEADERS = $(addprefix $(INCLUDE), \
libft.h)

PATHB = build/
PATHS = srcs/
PATHS_STR = $(addprefix $(PATHS), string/)
PATHS_CTYPE = $(addprefix $(PATHS), ctype/)
PATHS_IO = $(addprefix $(PATHS), io/)
PATHS_STD = $(addprefix $(PATHS), std/)
PATHS_LST = $(addprefix $(PATHS), list/)

include $(addprefix $(PATHS_STR), mod.mk)
include $(addprefix $(PATHS_CTYPE), mod.mk)
include $(addprefix $(PATHS_IO), mod.mk)
include $(addprefix $(PATHS_STD), mod.mk)
include $(addprefix $(PATHS_LST), mod.mk)

OBJS = $(addprefix $(PATHB), $(notdir $(SRCS:.c=.o)))

.PHONY = all bonus clean fclean re
all: $(NAME)

$(NAME): $(PATHB) $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(PATHB):
	$(MKDIR) $(PATHB)

clean:
	$(RM) $(PATHB)

fclean: clean
	$(RM) $(NAME)

re: fclean all