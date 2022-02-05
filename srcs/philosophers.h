/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaloui <adaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:51:11 by adaloui           #+#    #+#             */
/*   Updated: 2022/02/05 22:51:15 by adaloui          ###   ########.fr       */
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
	long int			latest_meal; 
	int					nb_ate; 
	struct s_rules		*rules;
	int					left_f; 
	int					right_f;
	pthread_t			thread_id;
}               t_philosopher;

typedef struct			s_rules
{
	int					philo_nb; 
	int					time_to_die; 
	int					time_to_eat; 
	int					time_to_sleep; 
	int					eating_time_nb; 
	int					have_all_eaten; 
	long int			first_ft_get_time;
	int					died; 
	pthread_mutex_t		print_message;
	pthread_mutex_t		forks[200]; 
	t_philosopher		philosophers[200];
	pthread_mutex_t		meal_check; 

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
long int	ft_get_time(void);
long long	ft_time_difference(long long present, long long past);
void		smart_sleep(long long time, t_rules *rules);

/*		FT_PHILOS_ROUTINE		*/
void	ft_sleep_and_think(t_rules *rules, t_philosopher *philo);
void	philo_eats(t_philosopher *philo);
void	philo_is_eating(t_rules *rules, t_philosopher *philo);
void	free_forks(t_rules *rules, t_philosopher *philo);
void	take_forks(t_rules *rules, t_philosopher *philo);



# endif