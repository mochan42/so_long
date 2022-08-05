# **************************************************************************** #
# VARIABLES

NAME				:= so_long

CC					:= clang
CFLAGS				:= -Wall -Wextra -Werror -g
RM					:= rm -rf
INCS				:= -I ./inc/
HEADER				:= ./inc/so_long.h

MLX_DIR				:= minilibx_opengl_20191021
MLX_A				:= ./minilibx_opengl_20191021/libmlx.a

FT_PRINTF_DIR		:= ft_printf
FT_PRINTF_A			:= ./ft_printf/ft_printf.a

GET_NEXT_LINE_DIR	:= get_next_line
GET_NEXT_LINE_A		:= ./get_next_line/get_next_line.a

SRC_DIR				:= ./src/
OBJ_DIR				:= ./obj/

# **************************************************************************** #
# COLORS

GREEN				:= \033[0;92m
YELLOW				:= \033[0;93m
BLUE				:= \033[0;94m
END_COLOR			:= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES			:= so_long.c window.c hooks.c map.c utils.c

OBJ_FILES			:= ${SRC_FILES:.c=.o}
SRC					:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ					:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# **************************************************************************** #
# RULES

all :	$(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	echo "make $(MLX_DIR)"
	make -C $(MLX_DIR)
	echo "make $(FT_PRINTF_DIR)"
	make -C $(FT_PRINTF_DIR)
	# echo "make $(GET_NEXT_LINE_DIR)"
	make -C $(GET_NEXT_LINE_DIR)
	$(CC) $(OBJ) $(MLX_A) $(FT_PRINTF_A) $(GET_NEXT_LINE_A) -framework OpenGL -framework AppKit -o $(NAME)
	echo "$(GREEN)$(NAME) compiled :)$(END_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean: 
	$(RM) $(OBJ)
	make clean -C $(MLX_DIR)
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all
	echo "$(GREEN) Cleaned all and rebuild $(NAME)!"

.PHONY:		all clean fclean re
