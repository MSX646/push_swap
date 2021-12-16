NAME = push_swap 
 
CC = gcc 
 
CFLAGS = -Wall -Werror -Wextra -I. -I libft/ 
 
LIBFT = -L libft -lft 
 
HEADER = push_swap.h 
 
SRC	   = main.c oper.c push_swap1.c push_swap2.c sorting.c

OBJS = ${SRC:.c=.o} 
 
all:   $(NAME)  
 
$(NAME): $(OBJS)  
	make -C libft/ 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) 
 
%.o:%.c $(HEADER) 
	${CC} ${CFLAGS} -c $< -o $@ 
 
clean: 
	make clean -C libft 
	rm -f $(OBJS) 
 
fclean: 
	make fclean -C libft 
	rm -f $(OBJS) 
	rm -f $(NAME) 
 
re:    fclean all 
 
.PHONY:   all clean fclean re
