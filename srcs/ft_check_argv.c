/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:50:57 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/05 22:51:01 by adaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_nb_argv(char **argv, int argc)
{
	if (argc == 5 || argc == 6)
		return (1);
	printf("\e[91mWrong number of arguments, you need 5\e[0m");
	printf("\e[91m you have \e[0m\e[41m%d\e[0m.\n", argc);
	return (0);
}

int	ft_check_alpha(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0 || (ft_is_not_minus(argv) == 0))
			{
				printf("\e[91mError, there is a non-numeric character.\e[0m\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_argv(char **argv)
{
	t_rules	check;

	check.philo_nb = ft_atoi(argv[1]);
	check.time_to_die = ft_atoi(argv[2]);
	check.time_to_eat = ft_atoi(argv[3]);
	check.time_to_sleep = ft_atoi(argv[4]);
	check.eating_time_nb = 0;
	if (check.philo_nb < 1 || check.philo_nb > 200
		|| check.time_to_die <= 0 || check.time_to_eat <= 0
		|| check.time_to_sleep <= 0)
	{
		ft_error_write_5_args(&check);
		return (0);
	}
	return (1);
}

int	ft_check_argv_2(char **argv)
{
	t_rules	check;

	check.philo_nb = ft_atoi(argv[1]);
	check.time_to_die = ft_atoi(argv[2]);
	check.time_to_eat = ft_atoi(argv[3]);
	check.time_to_sleep = ft_atoi(argv[4]);
	check.eating_time_nb = ft_atoi(argv[5]);
	if (check.philo_nb < 1 || check.philo_nb > 200
		|| check.time_to_die <= 0 || check.time_to_eat <= 0
		|| check.time_to_sleep <= 0 || check.eating_time_nb <= 0)
	{
		ft_error_write_6_args(&check);
		return (0);
	}
	return (1);
}

int	ft_check_all(char **argv, int argc)
{
	t_checker	checker;

	checker.i = -1;
	checker.j = -1;
	checker.k = -1;
	checker.i = ft_check_nb_argv(argv, argc);
	if (checker.i == 0)
		return (0);
	checker.j = ft_check_alpha(argv);
	if (checker.j == 0)
		return (0);
	if (argc == 5)
		checker.k = ft_check_argv(argv);
	else if (argc == 6)
		checker.k = ft_check_argv_2(argv);
	if (checker.k == 0)
		return (0);
	return (1);
}
