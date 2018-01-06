NAME = libftprintf.a

LIBFT_PATH = ./libft
LIBFT_SRC =	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_strdup.c		\
			ft_strcpy.c		\
			ft_strncpy.c	\
			ft_strcat.c		\
			ft_strncat.c	\
			ft_strlcat.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strnstr.c	\
			ft_strcmp.c		\
			ft_strncmp.c	\
			ft_atoi.c		\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_memalloc.c	\
			ft_memdel.c		\
			ft_strnew.c		\
			ft_strdel.c		\
			ft_strclr.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strequ.c		\
			ft_strnequ.c	\
			ft_strsub.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_strsplit.c	\
			ft_itoa.c		\
			ft_itoa_base.c	\
			ft_uitoa_base.c	\
			ft_putchar.c	\
			ft_putstr.c		\
			ft_putnstr.c	\
			ft_putendl.c	\
			ft_putnbr.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstmap.c		\
			ft_intlen.c		\
			ft_intabs.c		\
			ft_strndup.c	\
			ft_strcmpp.c	\
			ft_wordcnt.c	\
			ft_wordlen.c

PRINT_PATH = ./src
PRINT_SRC =	ft_printf.c \
			ft_fprintf.c \
			init.c \
			printf_meat.c \
			arg_handle.c \
			get_things.c \
			print_things.c \
			convert.c \
			charify.c \
			decimalfy.c \
			hexify.c \
			octalfy.c \
			pointerfy.c \
			stringify.c \
			wide_stringify.c \
			undecimalfy.c \
			error.c

OBJ = $(PRINT_SRC:.c=.o) $(LIBFT_SRC:.c=.o)
LIBFT = $(addprefix $(LIBFT_PATH)/, $(LIBFT_SRC))
PRINT = $(addprefix $(PRINT_PATH)/, $(PRINT_SRC))
SRC = $(LIBFT) $(PRINT)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC)
	@ar -rcs $(NAME) $(OBJ)
	@mkdir obj
	@mv $(OBJ) obj

clean:
	@rm -rf obj
	@echo "cleaned up objects"

fclean: clean
	rm -f $(NAME)

re: fclean all
