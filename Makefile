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
C_SRCS		:= client.c
S_SRCS		:= server.c
C_SRCS		:= $(addprefix $(SRCS_DIR), $(C_SRCS))
S_SRCS		:= $(addprefix $(SRCS_DIR), $(S_SRCS))

NAME		:= minitalk
CLIENT		:= client
SERVER		:= server

B_SRCS_DIR	:= bonus/
B_C_SRCS		:= client_bonus.c
B_S_SRCS		:= server_bonus.c
B_C_SRCS		:= $(addprefix $(SRCS_DIR), $(C_SRCS))
B_S_SRCS		:= $(addprefix $(SRCS_DIR), $(S_SRCS))

B_NAME		:=	minitalk_bonus
B_CLIENT	:= client_bonus
B_SERVER	:= server_bonus

LIBFT		:= ./libft/libft.a
LIBFT_INCLDIR	:= -I ./libft
PF_INCLDIR		:= -I ./libft/ft_printf_includes

CC			:= cc
RM			:= rm -f
CFLAGS		:= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${CLIENT} ${SERVER}

${CLIENT}:	${C_SRCS} ${LIBFT}
	${CC} ${CFLAGS} ${LIBFT_INCLDIR} ${PF_INCLDIR} ${C_SRCS} -o ${CLIENT} ${LIBFT}

${SERVER}:	${S_SRCS} ${LIBFT}
	${CC} ${CFLAGS} ${LIBFT_INCLDIR} ${PF_INCLDIR} ${S_SRCS} -o ${SERVER} ${LIBFT}

${LIBFT}:
	$(MAKE) -C ./libft

clean:
	${RM} ${SRCS_DIR}*.o
	${RM} ${B_SRCS_DIR}*.o
	$(MAKE) -C ./libft clean

fclean:	clean
	${RM} ${CLIENT} ${SERVER}
	$(MAKE) -C ./libft fclean

bonus:	${B_NAME}

${B_NAME}:	${B_CLIENT} ${B_SERVER}

${B_CLIENT}:	${B_C_SRCS} ${LIBFT}
	${CC} ${CFLAGS} ${LIBFT_INCLDIR} ${PF_INCLDIR} ${B_C_SRCS} -o ${B_CLIENT} ${LIBFT}

${B_SERVER}:	${B_S_SRCS} ${LIBFT}
	${CC} ${CFLAGS} ${LIBFT_INCLDIR} ${PF_INCLDIR} ${B_S_SRCS} -o ${B_SERVER} ${LIBFT}

re:		fclean all

do:		all clean

.PHONY:	all clean fclean re bonus do
