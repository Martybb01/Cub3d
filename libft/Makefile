NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

AR = ar rcs

SRCS = ./ctype/ft_isalnum.c \
	./ctype/ft_isalpha.c \
	./ctype/ft_isascii.c \
	./ctype/ft_isdigit.c \
	./ctype/ft_isprint.c \
	./ctype/ft_tolower.c \
	./ctype/ft_toupper.c \
	./ctype/ft_isspace.c \
	./ft_fd/ft_putchar_fd.c \
	./ft_fd/ft_putendl_fd.c \
	./ft_fd/ft_putnbr_fd.c \
	./ft_fd/ft_putnbrbase_fd.c \
	./ft_fd/ft_putstr_fd.c \
	./ft_fd/ft_putunsigned_fd.c \
	./ft_fd/ft_puthex_fd.c \
	./ft_fd/ft_putptr_fd.c \
	./gnl/ft_get_next_line.c \
	./gnl/ft_get_next_line_utils.c \
	./list/ft_lstadd_back.c \
	./list/ft_lstadd_front.c \
	./list/ft_lstclear.c \
	./list/ft_lstdelone.c \
	./list/ft_lstiter.c \
	./list/ft_lstlast.c \
	./list/ft_lstmap.c \
	./list/ft_lstnew.c \
	./list/ft_lstsize.c \
	./mem/ft_bzero.c \
	./mem/ft_memchr.c \
	./mem/ft_memcmp.c \
	./mem/ft_memcpy.c \
	./mem/ft_memmove.c \
	./mem/ft_memset.c \
	./not_standard/ft_itoa.c \
	./not_standard/ft_split.c \
	./not_standard/ft_substr.c \
	./not_standard/ft_uitoa.c \
	./not_standard/ft_issign.c \
	./not_standard/ft_free_matrix.c \
	./stdlib/ft_atoi_err.c \
	./stdlib/ft_atoi.c \
	./stdlib/ft_calloc.c \
	./string/ft_strchr.c \
	./string/ft_strdup.c \
	./string/ft_striteri.c \
	./string/ft_strjoin.c \
	./string/ft_strfjoin.c \
	./string/ft_strlcat.c \
	./string/ft_strlcpy.c \
	./string/ft_strlen.c \
	./string/ft_strmapi.c \
	./string/ft_strncmp.c \
	./string/ft_strnstr.c \
	./string/ft_strrchr.c \
	./string/ft_strtrim.c \
	./ft_printf/ft_printf.c


OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I../include

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
.SILENT: