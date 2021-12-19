NAME		=	libft.a

LIBFT_DIR	=	./

SRC			=	ft_atoi.c ft_isdigit.c ft_isspace.c ft_putchar_fd.c \
				ft_putstr_fd.c ft_str_isnumeric.c ft_swap.c ft_strlen.c \
				$(STACK)
				
OBJ			=	$(SRC:.c=.o)

HEADER		=   libft.h lst/lst.h

STACK_DIR	=	./lst
STACK		=	lst/ft_stack_new_node.c lst/ft_stackadd_front.c \
				lst/ft_stackadd_back.c lst/ft_stack_size.c \
				lst/ft_stack_last.c lst/ft_stack_return_first.c \
				lst/ft_stack_remove.c lst/ft_stack_has_bigger.c \
				lst/ft_stack_clear.c lst/ft_stack_issorted.c \
				lst/ft_stack_max.c lst/ft_stack_min.c \
				lst/ft_stack_duplicate_int.c lst/ft_stack_sort.c \
				lst/ft_stack_duplicate.c lst/ft_stack_getval.c \
				lst/ft_stack_find.c
STACK_O		=	$(STACK:.c=.o)

INC			= 	-I$(LIBFT_DIR) -I$(STACK_DIR)

CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
CLIB		=	ar -rc
RM			=	rm -f

all: $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAG) -c $< -o $(<:.c=.o) $(INC)


$(NAME): $(OBJ) 
	$(CLIB) $(NAME) $(OBJ)

lst: clean $(STACK_O)
	$(CLIB) $(NAME) $(STACK_O)

clean:
	$(RM) $(OBJ) $(STACK_O)

fclean:
	$(RM) $(OBJ) $(STACK_O)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re info
