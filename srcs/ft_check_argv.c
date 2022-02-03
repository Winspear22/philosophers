/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:12:53 by user42            #+#    #+#             */
/*   Updated: 2022/02/03 16:12:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_check_nb_argv(char **argv, int argc)
{
    if (argc == 5 || argc == 6)
        return (1);
    printf("\e[91mWrong number of arguments, you need 5 you have \e[0m\e[41m%d\e[0m.\n", argc);
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

int ft_check_argv(char **argv)
{
    t_rules check;

    check.nb_philo = ft_atoi(argv[1]);
    check.time_death = ft_atoi(argv[2]);
    check.time_eat = ft_atoi(argv[3]);
    check.time_sleep = ft_atoi(argv[4]);
    check.nb_eat = 0;
    if (check.nb_philo < 1 || check.nb_philo > 200 || check.time_death <= 0 || check.time_eat <= 0
		|| check.time_sleep <= 0)
    {
            ft_error_write_5_args(&check);
            return (0);
    }
    return (1);
}

int ft_check_argv_2(char **argv)
{
    t_rules check;

    check.nb_philo = ft_atoi(argv[1]);
    check.time_death = ft_atoi(argv[2]);
    check.time_eat = ft_atoi(argv[3]);
    check.time_sleep = ft_atoi(argv[4]);
    check.nb_eat = ft_atoi(argv[5]);
    if (check.nb_philo < 1 || check.nb_philo > 200 || check.time_death <= 0 || check.time_eat <= 0
		|| check.time_sleep <= 0 || check.nb_eat <= 0)
    {
            ft_error_write_6_args(&check);
            return (0);
    }
    return (1);
}

int ft_check_all(char **argv, int argc)
{
    t_checker checker;

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