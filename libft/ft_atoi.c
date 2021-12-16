#include "libft.h"

long long	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	long long int	num;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	neg = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			neg = -1;
	}
	num = 0;
	while (ft_isdigit(str[i]))
		num = (num * 10) + (neg * (str[i++] - '0'));
	return (num);
}
