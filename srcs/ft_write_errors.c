/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:51:24 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/05 23:13:56 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error_write_5_args(t_rules *check)
{
	if (check->philo_nb < 1 || check->philo_nb > 200)
	{
		printf("\e[91mError, you need a number of philosopher < 1 or > 200.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->philo_nb);
	}
	if (check->time_to_sleep <= 0)
	{
		printf("\e[91mError, the time to sleep cannot be < 0.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_to_sleep);
	}
	if (check->time_to_eat <= 0)
	{
		printf("\e[91mError, the time to eat cannot be < 0.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_to_eat);
	}
	if (check->time_to_die <= 0)
	{
		printf("\e[91mError, the time to die cannot be <= 0.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_to_die);
	}
}

void	ft_error_write_6_args(t_rules *check)
{
	if (check->philo_nb < 1 || check->philo_nb > 200)
	{
		printf("\e[91mError, you need a number of philosopher < 1 or > 200.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->philo_nb);
	}
	if (check->time_to_sleep <= 0)
	{
		printf("\e[91mError, the time to sleep cannot be < 0.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_to_sleep);
	}
	if (check->time_to_eat <= 0)
	{
		printf("\e[91mError, the time to eat cannot be < 0.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_to_eat);
	}
	if (check->time_to_die <= 0)
	{
		printf("\e[91mError, the time to die cannot be <= 0.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_to_die);
	}
	if (check->eating_time_nb <= 0)
	{
		printf("\e[91mError, the number of time to eat cannot be < 0.\n");
		printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->eating_time_nb);
	}
}

void	write_actions(t_rules *rules, int philo_id, char *str)
{
	pthread_mutex_lock(&(rules->print_message));
	if (!(rules->died))
	{
		printf("\e[96m%li ms\e[39m ", ft_get_time() - rules->first_ft_get_time);
		printf("%i ", philo_id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(rules->print_message));
}
