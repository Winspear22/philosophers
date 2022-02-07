/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_routine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:50:18 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/07 16:43:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_forks(t_rules *rules, t_philosopher *philo)
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

void	free_forks(t_rules *rules, t_philosopher *philo)
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

void	philo_is_eating(t_rules *rules, t_philosopher *philo)
{
	if (philo->nb_ate != rules->nb_eat)
	{
		pthread_mutex_lock(&(rules->meal_check));
		philo->nb_ate++;
		write_actions(rules, philo->id, "\e[35mis eating\e[39m");
		philo->latest_meal = ft_get_time();
		pthread_mutex_unlock(&(rules->meal_check));
	}
	smart_sleep(rules->time_to_eat, rules);
}

void	philo_eats(t_philosopher *philo)
{
	t_rules	*rules;

	rules = philo->rules;
	take_forks(rules, philo);
	philo_is_eating(rules, philo);
	free_forks(rules, philo);
}

void	ft_sleep_and_think(t_rules *rules, t_philosopher *philo)
{
	write_actions(rules, philo->id, "\e[93mis sleeping\e[39m");
	smart_sleep(rules->time_to_sleep, rules);
	write_actions(rules, philo->id, "\e[32mis thinking\e[39m");
}
