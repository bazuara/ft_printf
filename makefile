# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bazuara <bazuara@student.42madrid.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 03:11:01 by bazuara           #+#    #+#              #
#    Updated: 2019/12/08 11:32:42 by bazuara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft

LNAME = libftprintf.a

SOURCE = ft_printf.c

LIBSOURCE = src/lib/atoi.c \
			src/lib/isalpha.c \
			src/lib/itoa.c \
			src/lib/memcpy.c \
			src/lib/putendl_fd.c \
			src/lib/strchr.c \
			src/lib/strlcat.c \
			src/lib/strncmp.c \
			src/lib/substr.c \
			src/lib/bzero.c \
			src/lib/isascii.c \
			src/lib/memccpy.c \
			src/lib/memmove.c \
			src/lib/putnbr_fd.c \
			src/lib/strcmp.c \
			src/lib/strlcpy.c \
			src/lib/strnstr.c \
			src/lib/tolower.c \
			src/lib/calloc.c \
			src/lib/isdigit.c \
			src/lib/memchr.c \
			src/lib/memset.c\
			src/lib/putstr_fd.c \
			src/lib/strdup.c \
			src/lib/strlen.c \
			src/lib/strrchr.c \
			src/lib/toupper.c \
			src/lib/isalnum.c \
			src/lib/isprint.c \
			src/lib/memcmp.c \
			src/lib/putchar_fd.c \
			src/lib/split.c \
			src/lib/strjoin.c \
			src/lib/strmapi.c \
			src/lib/strtrim.c \
			src/lib/lstiter_bonus.c\
			src/lib/lstmap_bonus.c \
			src/lib/lstsize_bonus.c \
			src/lib/lstadd_front_bonus.c\
			src/lib/lstdelone_bonus.c \
			src/lib/lstlast_bonus.c \
			src/lib/lstnew_bonus.c

OBJ = $(SOURCE:.c=.o)

LIBOBJ = $(LIBSOURCE:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -c

all: $(NAME)

# Rule to build your object files and link them into a binary
$(NAME):
	gcc $(CFLAGS) $(LFLAGS) $(SOURCE) $(LIBSOURCE)
	ar rc $(LNAME) $(OBJ) $(LIBOBJ)
	ranlib $(LNAME)
	echo "Compiled '$(NAME)' successfully"${RESET}

# Rule to remove object files
clean:
	@rm -f $(LSOURCE) $(LBONUSSRC)
	@echo "Cleaned objects successfully"${RESET}

# Rule to remove binary, calls the 'clean' rule first
fclean: clean
	@rm -f $(LNAME)
	@echo "Removed '$(LNAME)' with success"${RESET}

# Rule to remove object files and binary, then re-build everything
re: fclean all

# Rules that are not linked with a filename should be listed here
.PHONY: all clean fclean re
