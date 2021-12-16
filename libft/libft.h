#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# include "lst/stack.h"

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif

long long	ft_atoi(const char *str);
int			ft_isdigit(int ch);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putnbr_fd(int n, int fd);
int			ft_str_isnumeric(char *str);
int			ft_isspace(int c);
void		ft_swap(int *a, int *b);
size_t		ft_strlen(const char *str);

#endif
