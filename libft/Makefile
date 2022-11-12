# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asasada <asasada@student.42tokyo.j>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 20:36:25 by asasada           #+#    #+#              #
#    Updated: 2022/11/06 13:26:55 by asasada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c

B_SRCS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

SRCS	+= ${B_SRCS}

SRCS	+= get_next_line.c get_next_line_utils.c

SRCS	+= ft_printf/flag_controls.c \
			ft_printf/format_cs.c \
			ft_printf/format_di.c \
			ft_printf/format_p.c \
			ft_printf/format_u.c \
			ft_printf/format_utils.c \
			ft_printf/format_xxpercent.c \
			ft_printf/ft_printf.c \
			ft_printf/read_precision.c

OBJS	= ${SRCS:.c=.o}

HEADERS	= libft.h \
			get_next_line.h \
			./ft_printf_includes/ft_printf.h \
			./ft_printf_includes/format_utils.h \
			./ft_printf_includes/info_controls.h \
			./ft_printf_includes/read_precision.h

NAME	= libft.a

INCLUDE		= -I ./
PF_INCLUDE	= -I ./ft_printf_includes

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

# %.o : %.c
.c.o:		${HEADERS}
	${CC} ${CFLAGS} ${INCLUDE} ${PF_INCLUDE} -c $< -o ${<:.c=.o}
# $@ is the target, and $< is the first prerequisite

${NAME}:	${OBJS} ${HEADERS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:		fclean all

${BONUS}:	${OBJS} ${HEADERS}
	ar rc ${NAME} ${OBJS}

.PHONY:	all clean fclean re bonus
