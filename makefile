# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 03:11:01 by bazuara           #+#    #+#              #
#    Updated: 2019/12/08 11:55:37 by bazuara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft

LNAME = libftprintf.a

SOURCE = ft_printf.c

OBJFOLDER = src/lib/

LIBSOURCE = src/lib/ft_atoi.c \
			src/lib/ft_isalpha.c \
			src/lib/ft_itoa.c \
			src/lib/ft_memcpy.c \
			src/lib/ft_putendl_fd.c \
			src/lib/ft_strchr.c \
			src/lib/ft_strlcat.c \
			src/lib/ft_strncmp.c \
			src/lib/ft_substr.c \
			src/lib/ft_bzero.c \
			src/lib/ft_isascii.c \
			src/lib/ft_memccpy.c \
			src/lib/ft_memmove.c \
			src/lib/ft_putnbr_fd.c \
			src/lib/ft_strcmp.c \
			src/lib/ft_strlcpy.c \
			src/lib/ft_strnstr.c \
			src/lib/ft_tolower.c \
			src/lib/ft_calloc.c \
			src/lib/ft_isdigit.c \
			src/lib/ft_memchr.c \
			src/lib/ft_memset.c\
			src/lib/ft_putstr_fd.c \
			src/lib/ft_strdup.c \
			src/lib/ft_strlen.c \
			src/lib/ft_strrchr.c \
			src/lib/ft_toupper.c \
			src/lib/ft_isalnum.c \
			src/lib/ft_isprint.c \
			src/lib/ft_memcmp.c \
			src/lib/ft_putchar_fd.c \
			src/lib/ft_split.c \
			src/lib/ft_strjoin.c \
			src/lib/ft_strmapi.c \
			src/lib/ft_strtrim.c \
			src/lib/ft_lstiter_bonus.c\
			src/lib/ft_lstmap_bonus.c \
			src/lib/ft_lstsize_bonus.c \
			src/lib/ft_lstadd_front_bonus.c\
			src/lib/ft_lstdelone_bonus.c \
			src/lib/ft_lstlast_bonus.c \
			src/lib/ft_lstnew_bonus.c

OBJ = $(SOURCE:.c=.o)

LIBOBJ = $(LIBSOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -c

all: $(NAME)

# Rule to build your object files and link them into a binary
$(NAME):
	gcc $(CFLAGS) $(LFLAGS) $(SOURCE) $(LIBSOURCE)
	mv -f *.o src/lib
	ar rc $(LNAME) $(OBJFOLDER)$(OBJ) $(LIBOBJ)
	ranlib $(LNAME)
	echo "Compiled '$(NAME)' successfully"${RESET}

# Rule to remove object files
clean:
	rm -f $(LIBOBJ) $(LBONUSSRC)
	echo "Cleaned objects successfully"${RESET}

# Rule to remove binary, calls the 'clean' rule first
fclean: clean
	rm -f $(LNAME)
	echo "Removed '$(LNAME)' with success"${RESET}

# Rule to remove object files and binary, then re-build everything
re: fclean all

# Rules that are not linked with a filename should be listed here
.PHONY: all clean fclean re
