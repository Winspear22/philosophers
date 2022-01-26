/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_calculator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:51:43 by user42            #+#    #+#             */
/*   Updated: 2022/01/25 17:40:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     ft_exit(char *str)
{
    ft_putstr_fd("Error ", 2);
    ft_putstr_fd(str, 2);
    return (0);
}

long int	timestamp(void)
{
	struct timeval	t;
	long long		time;

	time = 0;
	if (gettimeofday(&t, NULL) == -1)
        ft_exit("Error gettimeoftheday");
	time = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	return (time);
}

long long	time_diff(long long past, long long pres)
{
	return (pres - past);
}

void		smart_sleep(long long time, t_rules *rules)
{
	long long i;

	i = timestamp();
	while (!(rules->dieded))
	{
		if (time_diff(i, timestamp()) >= time)
			break ;
		usleep(50);
	}
}