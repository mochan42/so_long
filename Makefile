# **************************************************************************** #
# VARIABLES

NAME				:= so_long
BONUS				:= so_long_bonus

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
BONUS_DIR			:=	./bonus/
OBJ_DIR				:= ./obj/
B_OBJ_DIR			:= ./b_obj/

# **************************************************************************** #
# COLORS

GREEN				:= \033[0;92m
YELLOW				:= \033[0;93m
BLUE				:= \033[0;94m
END_COLOR			:= \033[0;39m

# **************************************************************************** #
# SOURCES

SRC_FILES			:=	so_long.c window.c hooks.c utils_1.c utils_2.c\
						map.c map_checks_1.c map_checks_2.c\
						moves_1.c moves_2.c moves_3.c moves_4.c

SRC_BONUS_FILES		:=	so_long_bonus.c window_bonus.c\
						hooks.c utils_1.c utils_2.c\
						map.c map_checks_1.c map_checks_2.c\
						moves_1_bonus.c moves_2_bonus.c\
						moves_3_bonus.c moves_4_bonus.c\
						utils_bonus.c\
						villain_3_bonus.c villain_2_bonus.c\
						villain_1_bonus.c\
						animation_1_bonus.c animation_2_bonus.c\
						animation_3_bonus.c

OBJ_FILES			:= ${SRC_FILES:.c=.o}
BONUS_FILES			:= ${SRC_BONUS_FILES:.c=.o}
SRC					:= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ					:= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
B_OBJ				:= $(addprefix $(BONUS_DIR), $(BONUS_FILES))

# **************************************************************************** #
# RULES

# all :	$(OBJ_DIR) $(NAME)
all : $(NAME)

$(NAME):  $(OBJ_DIR) $(OBJ)
	@echo "$(BLUE)make $(MLX_DIR)$(END_COLOR)"
	make -C $(MLX_DIR)
	@echo "$(BLUE)make $(FT_PRINTF_DIR)$(END_COLOR)"
	make -C $(FT_PRINTF_DIR)
	@echo "$(BLUE)make $(GET_NEXT_LINE_DIR)$(END_COLOR)"
	make -C $(GET_NEXT_LINE_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_A) $(FT_PRINTF_A) $(GET_NEXT_LINE_A) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled :)$(END_COLOR)"
# -C	:	make option that tells make to change directory before execution.

$(BONUS):  $(B_OBJ_DIR) $(B_OBJ)
	@echo "$(BLUE)make $(MLX_DIR)$(END_COLOR)"
	make -C $(MLX_DIR)
	@echo "$(BLUE)make $(FT_PRINTF_DIR)$(END_COLOR)"
	make -C $(FT_PRINTF_DIR)
	@echo "$(BLUE)make $(GET_NEXT_LINE_DIR)$(END_COLOR)"
	make -C $(GET_NEXT_LINE_DIR)
	$(CC) $(CFLAGS) $(B_OBJ) $(MLX_A) $(FT_PRINTF_A) $(GET_NEXT_LINE_A) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)$(NAME) with bonus compiled :)$(END_COLOR)"
# -C	:	make option that tells make to change directory before execution.

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS)  -c $< -o $@ $(INCS)
# -c	:	gcc option to compile each .c file into .o file.
# $<	:	represents the first prerequisite of the rule (each .c file 
#			contained in the src folder).
# -o	:	gcc option to define the name of the program (output) file :
#			"push_swap".
# $@	:	represents the filename of the target of the rule, i.e. each output
#			file which will be linked with the so_long.h header file.

$(B_OBJ_DIR)%.o : $(BONUS_DIR)%.c
	$(CC) $(CFLAGS)  -c $< -o $@ $(INCS)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(B_OBJ_DIR):
	@mkdir $(B_OBJ_DIR)

bonus: $(BONUS)

clean: 
	$(RM) $(OBJ)
	$(RM) $(B_OBJ)
	make clean -C $(MLX_DIR)
	make clean -C $(FT_PRINTF_DIR)
	make clean -C $(GET_NEXT_LINE_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(OBJ_DIR)
	$(RM) $(B_OBJ_DIR)
	make fclean -C $(FT_PRINTF_DIR)
	make fclean -C $(GET_NEXT_LINE_DIR)

re: fclean all
	@echo "$(GREEN) Cleaned all and rebuild $(NAME), $(MLX_DIR) , $(FT_PRINTF_DIR) and $(GET_NEXT_LINE_DIR)!$(END_COLOR)!"

.PHONY:		all clean fclean re

