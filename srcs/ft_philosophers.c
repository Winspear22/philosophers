/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 23:38:53 by user42            #+#    #+#             */
/*   Updated: 2022/02/03 16:22:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void take_forks(t_rules *rules, t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&(rules->forks[philo->left_f]));
		write_actions(rules, philo->id, "\e[34mhas taken a fork\e[39m");
		pthread_mutex_lock(&(rules->forks[philo->right_f]));
		write_actions(rules, philo->id, "\e[34mhas taken a fork\e[39m");
	}
	else
	{
		pthread_mutex_lock(&(rules->forks[philo->right_f]));
		write_actions(rules, philo->id, "\e[34mhas taken a fork\e[39m");
		pthread_mutex_lock(&(rules->forks[philo->left_f]));
		write_actions(rules, philo->id, "\e[34mhas taken a fork\e[39m");
	}
}

void free_forks(t_rules *rules, t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&(rules->forks[philo->left_f]));
		pthread_mutex_unlock(&(rules->forks[philo->right_f]));
	}
	else
	{
		pthread_mutex_unlock(&(rules->forks[philo->right_f]));
		pthread_mutex_unlock(&(rules->forks[philo->left_f]));
	}
}

void philo_is_eating(t_rules *rules, t_philosopher *philo)
{
	pthread_mutex_lock(&(rules->meal_check));
	write_actions(rules, philo->id, "\e[35mis eating\e[39m");
	philo->t_last_meal = timestamp();
	pthread_mutex_unlock(&(rules->meal_check));
	smart_sleep(rules->time_eat, rules);
	(philo->x_ate)++;
}

void	philo_eats(t_philosopher *philo)
{
	t_rules *rules;

	rules = philo->rules;
	take_forks(rules, philo);
	philo_is_eating(rules, philo);
	free_forks(rules, philo);
}

void	ft_sleep_and_think(t_rules *rules, t_philosopher *philo)
{
	write_actions(rules, philo->id, "\e[93mis sleeping\e[39m");
	smart_sleep(rules->time_sleep, rules);
	write_actions(rules, philo->id, "\e[32mis thinking\e[39m");
}

void	*routine(void *void_philosopher)
{
	int				i;
	t_philosopher	*philo;
	t_rules			*rules;

	i = 0;
	philo = (t_philosopher *)void_philosopher;
	rules = philo->rules;
	if (philo->id % 2 == 0)
		usleep(15000);
	while (!(rules->dieded))
	{
		philo_eats(philo);
		if (rules->all_ate)
			break ;
		ft_sleep_and_think(rules, philo);
		i++;
	}
	return (NULL);
}

void	exit_launcher(t_rules *rules, t_philosopher *philos)
{
	int i;
	
	if (rules->nb_philo == 1)
		i = 1;
	else
		i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(philos[i].thread_id, NULL);
		i++;
	}
	i = 0;
	if (rules->nb_philo != 1)
	{
		while (i < rules->nb_philo)
		{
			pthread_mutex_destroy(&(rules->forks[i]));
			i++;
		}
	}
	pthread_mutex_destroy(&(rules->print_message));
}

void	death_checker(t_rules *r, t_philosopher *p)
{
	int i;

	while (!(r->all_ate))
	{
		i = -1;
		while (++i < r->nb_philo && !(r->dieded))
		{
			pthread_mutex_lock(&(r->meal_check));
			if (time_diff(p[i].t_last_meal, timestamp()) > r->time_death)
			{
				write_actions(r, i, "\e[1m\e[91mdied\e[0m\e[39m");
				r->dieded = 1;
			}
			pthread_mutex_unlock(&(r->meal_check));
			usleep(100);
		}
		if (r->dieded)
			break ;
		i = 0;
		while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
			i++;
		if (i == r->nb_philo)
			r->all_ate = 1;
	}
}

int    ft_philosophers(t_rules *rules)
{
    int				i;
	t_philosopher	*phi;

	i = 0;
	phi = rules->philosophers;
	rules->first_timestamp = timestamp();
    while (i < rules->nb_philo)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, &routine, &(phi[i])))
			return (1);
		phi[i].t_last_meal = timestamp();
		i++;
	}
	death_checker(rules, rules->philosophers);
	exit_launcher(rules, phi);
	return (0);
}