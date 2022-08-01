# **************************************************************************** #
# VARIABLES

NAME		:= so_long

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf
INCS		:= -I ./inc/
HEADER		:= ./inc/so_long.h

MLX_DIR		:= minilibx_opengl_20191021
MLX_A		:= ./minilibx_opengl_20191021/libmlx.a

SRC_DIR		:= ./src/
OBJ_DIR		:= ./obj/

# **************************************************************************** #
# COLORS

GREEN		:= \033[0;92m
YELLOW		:= \033[0;93m
BLUE		:= \033[0;94m
END_COLOR	:= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES	:= so_long.c

OBJ_FILES	:= ${SRC_FILES:.c=.o}
SRC			:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# **************************************************************************** #
# RULES

all :	$(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	echo "make $(MLX_DIR)"
	make -C $(MLX_DIR)
	$(CC) $(OBJ) $(MLX_A) -framework OpenGL -framework AppKit -o $(NAME)
	echo "$(GREEN)$(NAME) compiled :)$(END_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean: 
	$(RM) $(OBJ)
	make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)

re: fclean all
	echo "$(GREEN) Cleaned all and rebuild $(NAME)!"

.PHONY:		all clean fclean re
