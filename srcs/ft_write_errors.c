/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 20:08:53 by user42            #+#    #+#             */
/*   Updated: 2022/02/03 16:22:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_error_write_5_args(t_rules *check)
{
    if (check->nb_philo < 1 || check->nb_philo > 200)
    {
        printf("\e[91mError, you need a number of philosopher < 1 or > 200.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->nb_philo);
    }
    if (check->time_sleep <= 0)
    {
        printf("\e[91mError, the time to sleep cannot be < 0.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_sleep);
    }
    if (check->time_eat <= 0)
    {
        printf("\e[91mError, the time to eat cannot be < 0.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_eat);
    }
    if (check->time_death <= 0)
    {
        printf("\e[91mError, the time to die cannot be <= 0.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_death);
    }
}

void    ft_error_write_6_args(t_rules *check)
{
    if (check->nb_philo < 1 || check->nb_philo > 200)
    {
        printf("\e[91mError, you need a number of philosopher < 1 or > 200.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->nb_philo);
    }
    if (check->time_sleep <= 0)
    {
        printf("\e[91mError, the time to sleep cannot be < 0.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_sleep);
    }
    if (check->time_eat <= 0)
    {
        printf("\e[91mError, the time to eat cannot be < 0.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_eat);
    }
    if (check->time_death <= 0)
    {
        printf("\e[91mError, the time to die cannot be <= 0.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->time_death);
    }
    if (check->nb_eat <= 0)
    {
        printf("\e[91mError, the number of time to eat cannot be < 0.\n");
        printf("\e[91mIt is currently \e[0m\e[41m%d\e[0m.\n", check->nb_eat);
    }
}

void		write_actions(t_rules *rules, int philo_id, char *str)
{
	pthread_mutex_lock(&(rules->print_message));
	if (!(rules->dieded))
	{
		printf("\e[96m%li ms\e[39m ", timestamp() - rules->first_timestamp);
		printf("%i ", philo_id + 1);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&(rules->print_message));
}