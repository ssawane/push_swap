NAME	=	push_swap
NAME_B	=	checker

SRCS	=	accept_utils.c\
			accept_utils_2.c\
			accept.c\
			accept_checks.c\
			four_elements.c\
			five_elements.c\
			gain_index.c\
			lst_nums_convert.c\
			lst_utils.c\
			main.c\
			operations.c\
			operations_2.c\
			push_center.c\
			three_elements.c\
			huge_elements.c\
			third_step.c\
			third_step_2.c\
			giant_leap.c\

SRCS_B	=	accept_utils.c\
			accept_utils_2.c\
			accept.c\
			accept_checks.c\
			gain_index.c\
			lst_nums_convert.c\
			lst_utils.c\
			checker_main.c\
			checker_utils.c\
			bonus_operations.c\
			bonus_operations_2.c\
			get_next_line.c\

HEADER	=	push_swap.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))
OBJ_B	=	$(SRCS_B:%.c=%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus	:
	@make OBJ="$(OBJ_B)" SRCS="$(SRCS_B)" NAME="$(NAME_B)" all

clean	:
	@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	@$(RM) $(NAME) $(NAME_B)

re		:	fclean all