#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 05:02:19 by hmakino           #+#    #+#              #
#    Updated: 2022/06/24 08:00:27 by hiroaki          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex
CFLAGS			=	-Wall -Wextra -Werror

#mandatory
SRCS			=	pipex.c get.c exec.c split.c free.c error.c utils.c
SRCS_PATH		= 	$(addprefix ./src/mandatory/, $(SRCS))
OBJS_PATH		=	$(SRCS_PATH:%.c=%.o)

#bonus
BONUS_SRCS		=	pipex_bonus.c get_bonus.c exec_bonus.c split_bonus.c \
					free_bonus.c error_bonus.c utils_bonus.c
BONUS_PATH		= 	$(addprefix ./src/bonus/, $(BONUS_SRCS))
BONUS_OBJS_PATH	=	$(BONUS_PATH:%.c=%.o)

ifdef WITH_BONUS
	OBJS_PATH = $(BONUS_OBJS_PATH)
endif

all: 			$(NAME)

$(NAME):		$(OBJS_PATH) $(LIBFT) $(GNL) $(DPRINTF)
				$(MAKE) -C ./libs/libft
				$(MAKE) -C ./libs/gnl
				$(MAKE) -C ./libs/ft_dprintf
				$(CC) $(OBJS_PATH) $(LIBFT) $(GNL) $(DPRINTF) $(CFLAGS) -o $(NAME)

LIBFT			=	./libs/libft/libft.a
GNL				=	./libs/gnl/libftgnl.a
DPRINTF			=	./libs/ft_dprintf/libftdprintf.a

clean:
				$(MAKE) -C ./libs/libft clean
				$(MAKE) -C ./libs/gnl clean
				$(MAKE) -C ./libs/ft_dprintf clean
				$(RM) $(OBJS_PATH)
				$(RM) $(BONUS_OBJS_PATH)

fclean:			clean
				$(RM) $(LIBFT)
				$(RM) $(GNL)
				$(RM) $(DPRINTF)
				$(RM) $(NAME)

re:				fclean all

bonus:
				make WITH_BONUS=1

.PHONY:			all clean fclean re bonus
