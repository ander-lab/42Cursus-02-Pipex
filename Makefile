# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 12:07:44 by Alejandro         #+#    #+#              #
#    Updated: 2021/10/25 07:20:04 by Alejandro        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc 
CFLAGS	= -Wall -Wextra -Werror -g
LIB 	= ar -rcs
RM		= /bin/rm -f
LIBFT	= ./libft/libft.a
LIBA	= pipex.a
NAME 	= pipex

INCLUDE	= -I./includes/
SRCS	= ./srcs/main.c ./srcs/utils.c ./srcs/path_cmd.c
OBJS	= $(SRCS:.c=.o)
COMP	= $(CC) $(LIBA) ${SRCS} -o ${NAME}

$(NAME):	${OBJS}
					@echo "\033[33m----Compiling libft----"
					@make -s -C ./libft
					@cp libft/libft.a ./$(NAME)
					${LIB} ${NAME} ${OBJS}
					$(COMP)
					@echo "\n\033[1;32mEverything done! ░░░░░░ ＼(>o<)ノ ░░░░░\n"

all: 		${NAME}

clean:
					@make clean -C ./libft
					@rm -f ${OBJS} ${OBJS_B}

fclean: 	clean
					@make fclean -C ./libft
					@rm -f $(NAME)
					@rm -f ${PROG}
					@echo "\n\033[31mEverything clean! ░░░░░░ ٩(╬ʘ益ʘ╬)۶ ░░░░░\n"

re:			fclean all

.PHONY: all clean fclean re bonus party
