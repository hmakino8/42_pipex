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

NAME	=	pipex
CFLAGS	=	-Wall -Wextra -Werror $(INC)
INC		=	-I./include -I./libs/libft/ -I./libs/gnl/

SRCS	=	main.c \
			get_info.c \
			exec_cmd.c \
			parse_cmd.c \
			error_exit.c \
			connect_pipes.c \
			pipex-helper.c

SRCS_PATH	= 	$(addprefix ./src/mandatory/, $(SRCS))
OBJS_PATH	=	$(SRCS_PATH:%.c=%.o)

BONUS_SRCS	=	main_bonus.c \
				get_info_bonus.c \
				exec_cmd_bonus.c \
				parse_cmd_bonus.c \
				error_exit_bonus.c \
				connect_pipes_bonus.c \
				pipex-helper_bonus.c

BONUS_PATH		= 	$(addprefix ./src/bonus/, $(BONUS_SRCS))
BONUS_OBJS_PATH	=	$(BONUS_PATH:%.c=%.o)

ifdef WITH_BONUS
	OBJS_PATH = $(BONUS_OBJS_PATH)
endif

all:	$(NAME)

$(NAME):	$(OBJS_PATH) $(LIBFT) $(GNL)
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/gnl
	$(CC) $(OBJS_PATH) $(LIBFT) $(GNL) $(CFLAGS) -o $(NAME)

LIBFT	=	./libs/libft/libft.a
GNL		=	./libs/gnl/libftgnl.a

clean:
	$(MAKE) -C ./libs/libft clean
	$(MAKE) -C ./libs/gnl clean
	$(RM) $(OBJS_PATH)
	$(RM) $(BONUS_OBJS_PATH)

fclean:	clean
	$(RM) $(LIBFT)
	$(RM) $(GNL)
	$(RM) $(NAME)

re:	fclean all

bonus:
	make WITH_BONUS=1

.PHONY:	all clean fclean re bonus
