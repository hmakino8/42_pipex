# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmakino <hmakino@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 05:02:19 by hmakino           #+#    #+#              #
#    Updated: 2022/06/14 00:54:35 by hmakino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftdprintf.a

SRCS		=	ft_dprintf.c \
				scrape.c \
				output.c \
				utils.c

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re bonus
