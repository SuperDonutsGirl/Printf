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

NAME			= libftprintf.a
HEADER			= ft_printf.h
CC				= gcc
FLAG			= -Wall -Wextra -Werror
OPTION			= -I ${HEADER} -c

SRC				= 	ft_printf.c 		 \
					ft_itoa.c \
					ft_print_characters.c ft_print_unsint.c \
					ft_print_hexa.c ft_print_ptr_hexa.c \
					ft_width_bonus.c 			ft_atoi_bonus.c 					ft_ttt_xX_bonus.c \
					ft_ttt_u_bonus.c 			ft_ttt_c_bonus.c 					\
					ft_ttt_s_bonus.c 			ft_ttt_di_bonus.c 					ft_ttt_p_bonus.c \
					ft_print_hexa_bonus.c 		ft_print_bonus.c	ft_strcmp.c
					
					
				  
OBJ				= ${SRC:.c=.o}

###			BONUS		PART
BONUS			=		

BONNUSOBJ = 	${BONUS:.c=.o}

.c.o:
	${CC} ${FLAG} ${OPTION} $< -o ${<:.c=.o}

${NAME}:	${OBJ}
	ar -rc ${NAME} ${OBJ} 

all:		${NAME}

bonus: ${OBJ} ${BONNUSOBJ}
	ar -rc ${NAME} ${OBJ} ${BONUS}

clean:
	rm -f ${OBJ} ${BONNUSOBJ}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY:	all bonus clean fclean re 

