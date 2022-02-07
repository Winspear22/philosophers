/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:50:43 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/07 16:41:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *void_philosopher)
{
	int				i;
	t_philosopher	*philo;
	t_rules			*rules;

	philo = (t_philosopher *)void_philosopher;
	rules = philo->rules;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (!(rules->died))
	{
		if (rules->have_all_eaten == 1)
			break ;
		philo_eats(philo);
		ft_sleep_and_think(rules, philo);
	}
	return (NULL);
}

void	exit_launcher(t_rules *rules, t_philosopher *philos)
{
	int	i;

	if (rules->philo_nb == 1)
		i = 1;
	else
		i = 0;
	while (i < rules->philo_nb)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	i = 0;
	if (rules->philo_nb != 1)
	{
		while (i < rules->philo_nb)
		{
			pthread_mutex_destroy(&(rules->forks[i]));
			i++;
		}
	}
	pthread_mutex_destroy(&(rules->print_message));
}

void	ft_is_ph_dead(t_philosopher *p, t_rules *r)
{
	int	i;

	while (r->have_all_eaten == 0)
	{
		i = -1;
		while (++i < r->philo_nb && !(r->died))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (ft_time_difference(ft_get_time(), p[i].latest_meal)
				> r->time_to_die)
			{
				write_actions(r, i, "\e[1m\e[91mdied\e[0m\e[39m");
				r->died = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->died)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->philo_nb && p[i].nb_ate >= r->nb_eat)
			i++;
		if (i == r->philo_nb)
			r->have_all_eaten = 1;
	}
}

int	ft_philosophers(t_rules *r)
{
	int				i;
	t_philosopher	*ph;

	i = 0;
	ph = r->philosophers;
	r->first_ft_get_time = ft_get_time();
	while (i < r->philo_nb)
	{
		if (pthread_create(&(ph[i].thread_id), NULL, &routine, &(ph[i])))
			return (1);
		ph[i].latest_meal = ft_get_time();
		i++;
	}
	ft_is_ph_dead(r->philosophers, r);
	exit_launcher(r, ph);
	if (r->have_all_eaten == 1)
	{
		usleep(1500);
		printf("\e[93mEach philos ate %d, no death !", r->nb_eat);
		printf("\e[1m SUCCESS !\n");
	}
	return (0);
}
