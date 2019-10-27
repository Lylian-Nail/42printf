SRCS += $(addprefix $(PATHS_LST), \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstadd_back.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c)

$(PATHB)%.o: $(PATHS_LST)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@