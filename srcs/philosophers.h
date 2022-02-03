/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 21:24:20 by user42            #+#    #+#             */
/*   Updated: 2022/02/03 16:22:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_checker
{
	int i;
	int j;
	int k;
}				t_checker;

typedef struct s_philosopher
{
	int					id;
	int					x_ate;
	int					left_f;
	int					right_f;
	long int			t_last_meal;
	struct s_rules		*rules;
	pthread_t			thread_id;
}               t_philosopher;

typedef struct			s_rules
{
	int					nb_philo;
	int					time_death;
	int					time_eat;
	int					time_sleep;
	int					nb_eat;
	int					dieded;
	int					all_ate;
	long int			first_timestamp;
    pthread_mutex_t		meal_check;
	pthread_mutex_t		forks[250];
	pthread_mutex_t		print_message;
	t_philosopher		philosophers[250];
}                       t_rules;

/*      FT_UTIL_CMD     */
int     ft_atoi(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int     ft_isdigit(char c);
int     ft_is_not_minus(char **argv);

/*      FT_CHECK_ARGV       */
int     ft_check_all(char **argv, int argc);

/*      FT_WRITE_ERRORS     */
void    ft_error_write_5_args(t_rules *check);
void    ft_error_write_6_args(t_rules *check);
void	write_actions(t_rules *rules, int id, char *string);

/*      FT_INIT_ALL     */
t_rules ft_init_all(t_rules *i, char **argv);

/*      FT_PHILOSOPHERS     */
int		ft_philosophers(t_rules *rules);

/*		FT_TIME_CALCULATOR		*/
long int	timestamp(void);
long long	time_diff(long long past, long long pres);
void		smart_sleep(long long time, t_rules *rules);

# endif