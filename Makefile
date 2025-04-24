# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 17:53:01 by zel-ghab          #+#    #+#              #
#    Updated: 2025/04/23 16:48:23 by zel-ghab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################
## ARGUMENTS

NAME 		= so_long
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g

###########################################
## LIBRAIRIES

PRINTF        = ./functions/ft_printf
LIBFT         = ./functions/libft
MINILIBX      = ./minilibx

IFLAGS        = -I $(PRINTF) -I $(LIBFT) -I $(MINILIBX)
LDFLAGS       = -L $(PRINTF) -L $(LIBFT) -L $(MINILIBX) -lft -lftprintf -lmlx -framework OpenGL -framework AppKit

###########################################
## SOURCES

SRC_FILES	= so_long.c \
		  game_management/game_management.c \
		  parsing/parsing.c \
		  parsing/set_matrice.c \
		  parsing/check_map.c \
		  parsing/check_data.c \
		  parsing/check_playable.c \
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
	@rm -f ${OBJ_FILES} game_management/*.o parsing/*.o utils/*.o minilibx/*.o
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
