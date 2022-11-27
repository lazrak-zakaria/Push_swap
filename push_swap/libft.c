#include <stdlib.h>
#include <stdio.h>

long long ft_atol(char *str)
{
	long long	answer;
	int			sign;
	int			i;

	i = 0;
	answer = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if(str[i++] == '-')
			sign = -1;
	
	while(str[i] >= '0' && str[i] <= '9')
		answer = (answer * 10) + (str[i++] - '0');
	return (answer * sign);
}

char	*ft_split()
{
	
}

int main()
{
	printf("%lld",ft_atol("+145"));
	return 0;
}