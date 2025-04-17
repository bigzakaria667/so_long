# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 17:53:01 by zel-ghab          #+#    #+#              #
#    Updated: 2025/04/17 17:03:33 by zel-ghab         ###   ########.fr        #
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
IFLAGS        = -I $(PRINTF) -I $(LIBFT)
LDFLAGS       = -L $(PRINTF) -L $(LIBFT) -lft -lftprintf

###########################################
## SOURCES

SRC_FILES	= so_long.c \
		  instructions/instructions.c \
		  parsing/parsing.c \
		  parsing/set_matrice.c \
		  parsing/check_map.c \
		  parsing/check_data.c \
		  utils/error.c \
		  utils/matrice.c
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
	@rm -f ${OBJ_FILES} parsing/*.o utils/*.o instructions/*.o
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
