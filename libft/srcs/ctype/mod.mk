SRCS += $(addprefix $(PATHS_CTYPE), \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isprint.c \
ft_isascii.c \
ft_tolower.c \
ft_toupper.c)

$(PATHB)%.o: $(PATHS_CTYPE)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@