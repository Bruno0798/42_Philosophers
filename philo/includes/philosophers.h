/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:59:27 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/30 17:01:00 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* Color codes for terminal output */
# define RED	"\033[1m\033[31m"
# define GREEN	"\033[1m\033[32m"
# define YELLOW   "\033[1m\033[33m"
# define BLUE     "\033[1m\033[34m"
# define ENDC	"\033[0m"

# define ARGS_ERROR "Wrong number of arguments\n\033[0m \
Try: \033[1m\033[32m./philo \033[1m\033[33mPhilosophers Number \
\033[1m\033[34mTime to die \033[1m\033[35mTime to eat \
 \033[1m\033[36mTime to sleep \033[1m\033[31m[Number of meals]\n\033[0m"
# define ARGS_INVALID "Wrong values: invalid characters, only numbers\n"
# define MUTEX_ERROR "Error: Mutex! \n"
# define MALLOC_ERROR "Error: Malloc! \n"
# define EAT "is eating"
# define FORK "has taken a fork"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

# define CLEAN_PHILOS 1
# define CLEAN_FORKS 2
# define CLEAN_FORK_MUTEXES 3
# define CLEAN_ALL_MUTEXES 4

typedef struct s_data
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	unsigned long	time;
	struct s_philo	*philos;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead;
	pthread_mutex_t	eating;
	pthread_mutex_t	start;
	bool			p_dead;
}				t_data;

typedef struct s_philo
{
	pthread_t		p_thread;
	int				id;
	int				n_eat;
	long			last_meal;
	pthread_t		thread;
	t_data			*data;
}				t_philo;

// ************************* CHECKS ************************* //
bool	ft_check_meals(t_philo *philo);
bool	ft_check_dead(t_philo *philo);

// ************************* INIT ************************* //
bool	ft_init(int argc, char **argv, t_data *data);
bool	ft_check_values(t_data *data);
bool	ft_init_struct(int argc, char **argv, t_data *data);

// ************************* MUTEX ************************* //
bool	ft_init_mutex(t_data *data);
bool	ft_init_forks(t_data *data);

// ************************* PHILO ACTIONS ************************* //
bool	ft_one_philo(t_philo *philo);
void	ft_waiter(t_data *data);
void	ft_take_forks(t_philo *philo);
void	ft_eat(t_philo *philo);
void	*ft_routine(void *arg);
void	ft_sleep(t_philo *philo);

// ************************* THREADS ************************* //
bool	ft_init_threads(t_data *data);
bool	ft_init_philos(t_philo **philos, t_data *data);
bool	ft_join_threads(t_data *data);

// ************************* UTILS ************************* //
bool	ft_check_char(int const argc, char **argv);
long	ft_get_time(void);
void	ft_print_status(char *str, t_philo *philo);
bool	ft_isdigit(char c);
int		ft_atoi(const char *str);

// ************************* UTILS ************************* //
void	ft_clean(t_data *data, int option);
#endif //PHILOSOPHERS_H
