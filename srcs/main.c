/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:23:47 by user42            #+#    #+#             */
/*   Updated: 2022/01/25 17:02:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char** argv) 
{
    t_rules philo;

    if (ft_check_all(argv, argc) == 0)
        return (0);
    philo = ft_init_all(&philo, argv);
    ft_philosophers(&philo);
    return (0);
}
