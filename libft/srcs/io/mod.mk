SRCS += $(addprefix $(PATHS_IO), \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c)

$(PATHB)%.o: $(PATHS_IO)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@