/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:51:50 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/05 23:15:51 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		r;

	i = 0;
	sign = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (sign == -1)
		r = -r;
	return (r);
}

int	ft_is_not_minus(char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	while (argv[i])
	{
		j = 1;
		if (argv[i][k] == '-' && argv[i][k + 1] == '\0')
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9' || c == '-')
		return (1);
	return (0);
}
