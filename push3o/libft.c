/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlazrak <zlazrak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:47:21 by zlazrak           #+#    #+#             */
/*   Updated: 2022/12/07 14:16:28 by zlazrak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	c_word(char	*str)
{
	int	answer;
	int	i;
	int	j;

	i = 0;
	answer = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != ' ' && str[i])
		{
			i++;
			j = 1;
		}
		while (str[i] == ' ')
			i++;
		answer += j;
	}
	return (answer);
}

char	**mem_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**ft_split2(char *str, char **answer, int i, int k)
{
	int	j;

	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		j = i;
		while (str[i] != ' ' && str[i])
			i++;
		answer[k] = malloc(sizeof(char) * (i - j + 1));
		if (!answer[k])
			return (mem_free(answer));
		i = j;
		j = 0;
		while (str[i] != ' ' && str[i])
			answer[k][j++] = str[i++];
		answer[k++][j] = '\0';
	}
	answer[k] = NULL;
	return (answer);
}

char	**ft_split(char *str)
{
	char	**answer;

	answer = malloc(sizeof(char *) * (c_word(str) + 2));
	if (!answer)
		return (NULL);
	answer[0] = malloc(sizeof(char));
	if (!answer[0])
	{
		free (answer);
		return (NULL);
	}
	answer[0][0] = '\0';
	return ((ft_split2(str, answer, 0, 1)));
}

void	ft_bzero(void *a, int n)
{
	unsigned char	*c;
	int				i;

	c = (unsigned char *)a;
	i = 0;
	while (i < n)
		c[i++] = 0;
}
