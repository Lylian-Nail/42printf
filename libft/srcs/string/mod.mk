SRCS += $(addprefix $(PATHS_STR), \
ft_memset.c \
ft_bzero.c \
ft_calloc.c \
ft_memcpy.c \
ft_memccpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strlen.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strdup.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strnstr.c \
ft_substr.c \
ft_split.c \
ft_strmapi.c)

$(PATHB)%.o: $(PATHS_STR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@