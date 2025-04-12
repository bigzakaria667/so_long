# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 17:53:01 by zel-ghab          #+#    #+#              #
#    Updated: 2025/04/12 16:59:12 by zel-ghab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################
## ARGUMENTS

NAME 		= so_long
CC		= gcc
CFLAGS		= -Wall -Wextra -Werror -g

###########################################
## LIBRAIRIES

PRINTF        = ./functions/ft_printf
LIBFT         = ./functions/libft
IFLAGS        = -I $(PRINTF) -I $(LIBFT) -I functions/get_next_line
LDFLAGS       = -L $(PRINTF) -L $(LIBFT) -lft -lftprintf

###########################################
## SOURCES

SRC_FILES	= so_long.c \
		  management/parsing/parsing.c\
		  management/parsing/check_map.c\
		  management/parsing/set_matrice.c\
		  management/utils/error.c \
		  functions/get_next_line/get_next_line.c \
		  functions/get_next_line/get_next_line_utils.c
OBJ_FILES	= $(SRC_FILES:.c=.o)

###########################################
## RULES

all : ${NAME}

${NAME} : ${OBJ_FILES}
	@make -s -C ${PRINTF}
	@make -s -C ${LIBFT}
	@${CC} ${CFLAGS} ${OBJ_FILES} ${LDFLAGS} -o ${NAME}
	@echo "✅ Successful compiliation!"

%.o : %.c
	@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean :
	@rm -f ${OBJ_FILES} management/parsing/*.o management/utils/*.o function/get_next_line/*.o
	@make -s clean -C $(PRINTF)
	@make -s clean -C $(LIBFT)
	@echo "🧹 Objects files deleted."

fclean : clean
	@make -s fclean -C $(LIBFT)
	@make -s fclean -C $(PRINTF)
	@rm -rf ${NAME}
	@echo "🧹 Reset all!"

re : fclean all

.PHONY: all clean fclean re
