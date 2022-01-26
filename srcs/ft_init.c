/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:36:32 by user42            #+#    #+#             */
/*   Updated: 2022/01/25 21:51:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_init_all_mutex(t_rules *philo)
{
    int i;

    i = philo->nb_philo;
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

    i->nb_philo = ft_atoi(argv[1]);
    k = i->nb_philo;
    i->time_death = ft_atoi(argv[2]);
    i->time_eat = ft_atoi(argv[3]);
    i->time_sleep = ft_atoi(argv[4]);
    i->nb_eat = 0;
    if (argv[5])
        i->nb_eat = ft_atoi(argv[5]);
    else 
        i->nb_eat = -1;
    while (--k >= 0)
    {
        i->philosophers[k].id = k;
        i->philosophers[k].x_ate = 0;
		i->philosophers[k].left_f = k;
		i->philosophers[k].right_f = (k + 1) % i->nb_philo;
        i->philosophers[k].t_last_meal = 0;
        i->philosophers[k].rules = i;
    }
    ft_init_all_mutex(i);
    return (*i);
}