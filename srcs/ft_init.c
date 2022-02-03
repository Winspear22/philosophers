/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:36:32 by user42            #+#    #+#             */
/*   Updated: 2022/02/03 21:09:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_init_all_mutex(t_rules *philo)
{
    int i;

    i = philo->philo_nb;
    if (pthread_mutex_init(&(philo->print_message), NULL))
		return (1);
    if (pthread_mutex_init(&(philo->meal_check), NULL))
		return (1);
    while (--i >= 0)
    {
        if (pthread_mutex_init(&(philo->forks[i]), NULL)) //j'initialise le nombre de mutex en fonction du nombre de fourchettes (250)
			return (1);
    }
    return (0);

}

t_rules ft_init_all(t_rules *i, char **argv)
{
    int k;

    i->philo_nb = ft_atoi(argv[1]);
    k = i->philo_nb;
    i->time_to_die = ft_atoi(argv[2]);
    i->time_to_eat = ft_atoi(argv[3]);
    i->time_to_sleep = ft_atoi(argv[4]);
    i->eating_time_nb = 0;
    if (argv[5])
        i->eating_time_nb = ft_atoi(argv[5]);
    else 
        i->eating_time_nb = -1;
    while (--k >= 0)
    {
        i->philosophers[k].id = k;
        i->philosophers[k].nb_ate = 0;
		i->philosophers[k].left_f = k;
		i->philosophers[k].right_f = (k + 1) % i->philo_nb;
        i->philosophers[k].latest_meal = 0;
        i->philosophers[k].rules = i;
    }
    ft_init_all_mutex(i);
    return (*i);
}