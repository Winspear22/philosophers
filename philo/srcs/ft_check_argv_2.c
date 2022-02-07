/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:07:34 by user42            #+#    #+#             */
/*   Updated: 2022/02/07 17:24:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_check_number_size(char **argv, int argc)
{
    t_sizenb check;

    check.time_to_die = ft_strlen(argv[2]);
	check.time_to_eat = ft_strlen(argv[3]);
    check.time_to_sleep = ft_strlen(argv[4]);
    if (argc == 5)
    {
	    check.nb_eat = 0;
        if (check.time_to_die > 11 || check.time_to_eat > 11
            || check.time_to_sleep > 11)
        {
            printf("\e[91mError, number too large.\e[0m\n");
            return (0);
        }
    }
    if (argc == 6)
    {
	    check.nb_eat = ft_strlen(argv[5]);
        if (check.time_to_die > 11 || check.time_to_eat > 11
            || check.time_to_sleep > 11 || check.nb_eat > 11)
        {
            printf("\e[91mError, number too large.\e[0m\n");
            return (0);
        }    
    }
    return (1);
}