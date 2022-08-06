# **************************************************************************** #
# VARIABLES

NAME				:= get_next_line.a

CC					:= gcc
CFLAGS				:= -Wall -Wextra -Werror
RM					:= rm -rf
INCS				:= -I
HEADER				:= get_next_line.h

# **************************************************************************** #
# COLORS

GREEN				:= \033[0;92m
YELLOW				:= \033[0;93m
BLUE				:= \033[0;94m
END_COLOR			:= \033[0;39m

# **************************************************************************** #
# SOURCES

SRCS				:=	get_next_line.c get_next_line_utils.c

OBJS				:= ${SRCS:.c=.o}

# **************************************************************************** #
# RULES

all :	$(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY:		all clean fclean re
