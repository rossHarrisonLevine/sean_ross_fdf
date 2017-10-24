# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevine <rlevine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/03 15:21:19 by rlevine           #+#    #+#              #
#    Updated: 2017/10/24 11:22:53 by sjones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME=libft.a

# CC=gcc

# CFLAGS=-Wall -Wextra -Werror -O3

# RM=rm -f

# LDFLAGS=-L.

# LDLIBS=-lft

# HDDIRS=-I includes/

# SRCDIR = $(addprefix srcs/,$(SRC))

# SRC = $(SRC1) $(SRC2) $(SRC3) $(EXTRA)

# # Libft Part I
# SRC1 =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
# 		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
# 		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
# 		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
# 		ft_atoi.c ft_itoa.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
# 		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c \
# 		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putstr.c \
# 		ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_wlen.c
# # Libft Part II
# SRC2 =	ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
# 		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
# 		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c
# # Libft Part III Bonus
# SRC3 = ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
# 		ft_lstmap.c 
# # Libft Perso
# EXTRA =	ft_pwr.c ft_abs.c ft_cnt_parts.c ft_countwhite.c ft_islower.c \
# ft_isneg.c ft_isupper.c ft_nbrlen.c

# OBJ=$(SRC:.c=.o)

# $(NAME): $(SRCDIR)
# 	$(CC) $(CFLAGS) -c $(SRCDIR) $(HDDIRS)
# 	ar rc $(NAME) $(OBJ)
# 	ranlib $(NAME)

# all: $(NAME)

# clean:
# 	$(RM) $(OBJ)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean $(NAME)

# .PHONY: clean fclean

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -g
.PHONY = all clean fclean re

SRC = 	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_itoa.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_putchar.c \
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putstr.c \
		ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_wlen.c\
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c\
		ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c\
		ft_lstmap.c ft_pwr.c ft_abs.c ft_cnt_parts.c ft_countwhite.c ft_islower.c \
		ft_isneg.c ft_isupper.c ft_nbrlen.c ft_strndup.c get_next_line.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean $(NAME)
