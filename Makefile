NAME	=	push_swap

SRCS	=	accept_utils.c\
			accept.c\
			four_five_elements.c\
			gain_index.c\
			lst_nums_convert.c\
			lst_utils.c\
			main.c\
			operations.c\
			push_center.c\
			three_elements.c\
			huge_elements.c\
			third_step.c\
			giant_leap.c\

HEADER	=	push_swap.h
OBJ		=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re		:	fclean all