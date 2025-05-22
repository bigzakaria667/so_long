# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zel-ghab <zel-ghab@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 17:53:01 by zel-ghab          #+#    #+#              #
#    Updated: 2025/05/21 16:37:30 by zel-ghab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################################
## ARGUMENTS

NAME 		= so_long
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g

###########################################
## LIBRARIES

PRINTF        = ./functions/ft_printf
LIBFT         = ./functions/libft
MINILIBX      = ./minilibx

IFLAGS        = -I $(PRINTF) -I $(LIBFT) -I $(MINILIBX) -I .
LDFLAGS       = -L $(PRINTF) -L $(LIBFT) -L $(MINILIBX) -lft -lftprintf

###########################################
## SOURCES

SRC_FILES	= so_long.c \
		  game_management/game_management.c \
		  game_management/generate_texture.c \
		  game_management/move_player.c \
		  parsing/parsing.c \
		  parsing/set_matrice.c \
		  parsing/check_map.c \
		  parsing/check_data.c \
		  parsing/check_playable.c \
		  utils/error.c \
		  utils/game.c \
		  utils/matrice.c \
		  utils/map.c \
		  utils/destroy.c

OBJ_FILES	= $(SRC_FILES:.c=.o)

###########################################
## OS DETECTION

UNAME_S := $(shell uname -s)

# If OS is Linux
ifeq ($(UNAME_S), Linux)
    OS = LINUX
    MLX_FLAGS = -lmlx -L minilibx/ -lXext -lX11 -lm -lz
# If OS is macOS
else
    OS = MAC
    MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -L minilibx/
endif

###########################################
## RULES

all : ${NAME}

${NAME} : ${OBJ_FILES}
	@echo "🛠️  Compiling libraries..."
	@make -s -C ${PRINTF}
	@make -s -C ${LIBFT}
	@make -s -C ${MINILIBX}
	@${CC} ${CFLAGS} ${OBJ_FILES} ${LDFLAGS} ${MLX_FLAGS} -o ${NAME}
	@echo "✅ Compilation successful for $(OS)!"

%.o : %.c
	@${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@

clean :
	@rm -f ${OBJ_FILES} game_management/*.o parsing/*.o utils/*.o
	@make -s clean -C $(PRINTF)
	@make -s clean -C $(LIBFT)
	@make -s clean -C $(MINILIBX)
	@echo "🧹 Object files removed."

fclean : clean
	@make -s fclean -C $(LIBFT)
	@make -s fclean -C $(PRINTF)
	@rm -rf ${NAME}
	@echo "🧹 Everything is cleaned."

re : fclean all

###########################################
## CUSTOM COMMANDS

linux:
	@$(MAKE) fclean
	@$(MAKE) all OS=LINUX

mac:
	@$(MAKE) fclean
	@$(MAKE) all OS=MAC

.PHONY: all clean fclean re linux mac
