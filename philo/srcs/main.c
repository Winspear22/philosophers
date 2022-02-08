/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:51:35 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/08 07:17:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_rules	philo;

	if (ft_check_all(argv, argc) == 0)
		return (0);
	philo = ft_init_all(&philo, argv);
	ft_philosophers(&philo);
	return (0);
}
