# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bazuara <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 11:45:30 by bazuara           #+#    #+#              #
#    Updated: 2019/11/25 13:41:03 by bazuara          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft

LNAME = libft.a

SOURCE = ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c  ft_putendl_fd.c \
		 ft_strchr.c  ft_strlcat.c ft_strncmp.c ft_substr.c ft_bzero.c \
		 ft_isascii.c ft_memccpy.c ft_memmove.c ft_putnbr_fd.c  ft_strcmp.c \
		 ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_calloc.c  ft_isdigit.c \
		 ft_memchr.c  ft_memset.c  ft_putstr_fd.c  ft_strdup.c  ft_strlen.c \
		 ft_strrchr.c ft_toupper.c ft_isalnum.c ft_isprint.c ft_memcmp.c \
		 ft_putchar_fd.c ft_split.c   ft_strjoin.c ft_strmapi.c ft_strtrim.c

LSOURCE = $(SOURCE:.c=.o)

BONUSSRC = ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c\
		   ft_lstmap_bonus.c ft_lstsize_bonus.c ft_lstadd_front_bonus.c\
		   ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c 

LBONUSSRC = $(BONUSSRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -c

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) $(LFLAGS) $(SOURCE)
	@ar rc $(LNAME) $(LSOURCE)
	@ranlib $(LNAME)
	@echo "Compiled '$(NAME)' successfully"${RESET}

bonus: 
	gcc $(CFLAGS) $(LFLAGS) $(BONUSSRC)
	ar rcs $(LNAME) $(LBONUSSRC)
	@echo "Compiled '$(NAME)' with bonus successfully"${RESET}

clean:
	@rm -f $(LSOURCE) $(LBONUSSRC)
	@echo "Cleaned objects successfully"${RESET}

fclean:
	@rm -f $(LNAME)
	@echo "Removed '$(LNAME)' with success"${RESET}

re: fclean all

.PHONY: clean fclean
