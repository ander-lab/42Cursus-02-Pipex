# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajimenez <ajimenez@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/23 12:07:44 by Alejandro         #+#    #+#              #
#    Updated: 2021/12/03 18:01:30 by ajimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc 
CFLAGS	= -Wall -Wextra -Werror -g
SAN		= -fsanitize=address
LIB 	= ar -rcs
RM		= /bin/rm -rf

LIBFT	= ./libft/libft.a
LIBP	= pipex.a 

NAME 	= pipex 
INCLUDE	= -I./includes/
SRCS	= ./srcs/main.c ./srcs/path_cmd.c

OBJS	= $(SRCS:.c=.o)
COMP	= $(CC) $(LIBP) $(SRCS) -o $(NAME)
SANCOMP	= $(CC) $(SAN) $(LIBP) $(SRCS) -g3 -o $(NAME)

all: 		$(NAME)

$(NAME):	$(OBJS)
					@echo "\033[33m----Compiling libft----"
					@make -C ./libft
					@cp libft/libft.a ./$(LIBP)
					$(LIB) $(LIBP) $(OBJS)
					$(COMP)
					@echo "\n\033[1;32mEverything done! ░░░░░░ ＼(>o<)ノ ░░░░░\033[39m\n"

fsanitize:			$(OBJS)
					@echo "\n\033[33mMaking libft! ░░░░░░ /(ಠ_ಠ)\ ░░░░░\033[39m\n"
					@make -s -C ./libft
					@cp libft/libft.a ./$(LIBP)
					$(LIB) $(LIBP) $(OBJS)
					$(SANCOMP)
					@echo "\n\033[1;32mEverything done! ░░░░░░ ＼(>o<)ノ ░░░░░\033[39m\n"

clean:
					@make clean -C ./libft
					$(RM) $(OBJS) $(OBJS_B)

fclean: 	clean
					@make fclean -C ./libft
					$(RM) $(NAME)
					$(RM) $(PROG)
					$(RM) $(LIBP)
					@echo "\n\033[31mEverything fcleaned! ░░░░░░ ٩(╬ʘ益ʘ╬)۶ ░░░░░\n\033[39m"

re:			fclean all

.PHONY: all clean fclean re
