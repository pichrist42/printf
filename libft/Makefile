# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pichrist <pichrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/14 07:46:41 by pichrist          #+#    #+#              #
#    Updated: 2017/01/30 03:48:01 by pichrist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isprint.c ft_iterative_power.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memset.c ft_power.c \
	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
	ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
	ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
	ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
	ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
	ft_strstr.c ft_strsub.c ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c ft_memmove.c ft_abs.c ft_strchrp.c ft_strdupu.c ft_strdupa.c \
	ft_strisalnum.c ft_strisalpha.c ft_strisascii.c ft_isdigit.c \
	ft_strisdigit.c
OBJ = $(SRC:.c=.o)
.PHONY: all fclean re clean

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra $(SRC) -c -I .
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Object files\t\033[1;32m[Created]\033[0m"
	@echo "libft.a\t\t\033[1;32m[Created]\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "Object files\t\033[1;34m[Removed]\033[0m"

fclean: clean
	@rm -f libft.a
	@echo "libft.a\t\t\033[1;34m[Removed]\033[0m"

re: fclean all
