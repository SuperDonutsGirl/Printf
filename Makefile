# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 16:06:15 by pamartin          #+#    #+#              #
#    Updated: 2022/01/02 16:06:16 by pamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
HEADER		= ft_printf.h
CC			= gcc
FLAG		= -Wall -Wextra -Werror
OPTION		= -I ${HEADER} -c

FILLSRC		= ft_printf.c \
				ft_print_characters.c ft_print_unsint.c ft_itoa.c \
				ft_print_hexa.c ft_print_ptr_hexa.c \
				ft_width.c ft_atoi.c 

FILLOBJ		= ${FILLSRC:.c=.o}

.c.o:
	${CC} ${FLAG} ${OPTION} $< -o ${<:.c=.o}

${NAME}:	${FILLOBJ}
	ar -rc ${NAME} ${FILLOBJ}

#bonus: ${FILLOBJ}
	#ar -rc ${NAME} ${FILLOBJ}

all:		${NAME}

clean:
	rm ${FILLOBJ}

fclean:		clean
	rm ${NAME}

re:			fclean all

#.PHONY: bonus all clean fclean re 

