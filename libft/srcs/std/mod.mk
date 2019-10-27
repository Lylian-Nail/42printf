SRCS += $(addprefix $(PATHS_STD), \
ft_atoi.c \
ft_itoa.c)

$(PATHB)%.o: $(PATHS_STD)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@