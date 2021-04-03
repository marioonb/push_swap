SRCS_SW=	all/linked_list_utils.c \
			all/linked_list_tools.c \
			all/parse_utils.c \
			all/inverse_rotate.c \
			all/push.c \
			all/rotate.c \
			all/swap.c \

SRCS_CH=	all/inverse_rotate.c \
			all/push.c \
			all/rotate.c \
			all/linked_list_utils.c \
			all/linked_list_tools.c \
			all/parse_utils.c \
			all/swap.c \
			chaine.c

FLAGS = -Werror -Wextra -Wall -fsanitize=address -g

RM = rm -f

OBJS = inverse_rotate.o lib.o push.o rotate.o swap.o lib.o chaine.o \
linked_list_utils.o linked_list_tools.o parse_utils.o

LIB = ./libft/libft.a

NAME_SW = push_swap

NAME_CH = checker

all:	$(NAME_SW) $(NAME_CH)

$(NAME_CH):
		@make -C libft/ libft.a
		gcc -c $(FLAGS) $(SRCS_CH)
		gcc $(FLAGS) $(SRCS_CH) $(LIB) checker_prog/checker.c -o $(NAME_CH)

$(NAME_SW):
		@make -C libft/ libft.a
		gcc -c $(FLAGS) $(SRCS_SW)
		gcc $(FLAGS) $(SRCS_SW) $(LIB) push_swap_prog/push_swap.c -o $(NAME_SW)

clean :
	make -C libft/ clean
	$(RM) $(OBJS)

fclean : clean
	make -C libft/ fclean
	$(RM) $(NAME_CH) $(NAME_SW)

debug :
	@make -C libft/ libft.a
	gcc -c -D DEBUG=1 $(FLAGS) $(SRCS_CH)
	gcc -D DEBUG=1 $(FLAGS) $(SRCS_CH) $(LIB) checker_prog/checker.c -o $(NAME_CH)
	gcc -c -D DEBUG=1 $(FLAGS) $(SRCS_SW)
	gcc -D DEBUG=1 $(FLAGS) $(SRCS_SW) $(LIB) push_swap_prog/push_swap.c -o $(NAME_SW)

re : fclean all

.PHONY: all clean fclean re