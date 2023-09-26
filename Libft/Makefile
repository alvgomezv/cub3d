# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomez-d <fgomez-d@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/01 13:41:20 by fgomez-d          #+#    #+#              #
#    Updated: 2023/07/02 12:34:42 by fgomez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror -I.
NAME=libft.a
SRC=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_putnbr_base_fd.c ft_putunbr_base_fd.c ft_putstrn_fd.c\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_printf.c get_next_line.c \
	get_next_line_utils.c ft_count_char.c ft_lstrpl.c ft_printf_fd.c \
	ft_lstpop.c ft_lstpop_idx.c ft_stk_p.c ft_stk_r.c ft_stk_rr.c \
	ft_stk_s.c ft_stknew.c ft_stkdelone.c ft_stkadd_top.c ft_stkiter.c \
	ft_stkclear.c ft_stklast.c ft_stksize.c ft_stkpop.c ft_stkpop_idx.c \
	ft_stknewfirst.c ft_getstkidx.c ft_getstknode.c ft_quick_sort.c \
	ft_abs.c ft_minmax.c ft_atoi_base.c ft_reg_calloc.c
	

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re