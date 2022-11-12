# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 15:07:17 by asasada           #+#    #+#              #
#    Updated: 2022/11/12 15:07:17 by asasada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR	:= source/
SRCS		:= client.c \
				server.c
SRCS		:= $(addprefix $(SRCS_DIR), $(SRCS))
OBJS		:= ${SRCS:.c=.o}

HEADERS 	:=	./includes/solong.h \
NAME		:= minitalk

B_SRCS_DIR	:= bonus/
B_SRCS		:= client_bonus.c \
				server_bonus.c
B_SRCS		:= $(addprefix $(B_SRCS_DIR), $(B_SRCS))
B_OBJS		:= ${B_SRCS:.c=.o}

B_INCLDIR	:=	-I ./bonus/includes
B_HEADERS	:=	./bonus/includes/solong_bonus.h \
				./bonus/includes/math_utils_bonus.h
B_NAME		:=	solong_bonus

LIBFT		:= ./libft/libft.a

INCLDIR			:= -I ./includes
LIBFT_INCLDIR	:= -I ./libft
PF_INCLDIR		:= -I ./libft/ft_printf_includes

CC			:= cc
RM			:= rm -f
CFLAGS		:= -Wall -Wextra -Werror

all:		${NAME}

${OBJS}:	${SRCS_DIR}%.o : ${SRCS_DIR}%.c
	${CC} ${CFLAGS} ${INCLDIR} ${LIBFT_INCLDIR} ${PF_INCLDIR} -c $< -o $@

${NAME}:	${OBJS} ${HEADERS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} ${LIBFT}

${LIBFT}:
	$(MAKE) -C ./libft

clean:
	${RM} ${OBJS} ${B_OBJS}
	$(MAKE) -C ./libft clean

fclean:	clean
	${RM} ${NAME} ${B_NAME}
	$(MAKE) -C ./libft fclean

${B_OBJS}:	${B_SRCS_DIR}%.o : ${B_SRCS_DIR}%.c
	${CC} ${CFLAGS} ${B_INCLDIR} ${LIBFT_INCLDIR} ${PF_INCLDIR} -c $< -o $@

${B_NAME}:	${B_OBJS} ${B_HEADERS} ${LIBFT}
	${CC} ${CFLAGS} ${B_OBJS} -o ${B_NAME} ${LIBFT}

bonus:	${B_NAME}

re:		fclean all

do:		all clean

.PHONY:	all clean fclean re bonus do
