/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:21:36 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/27 14:03:43 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	ft_one_philo(t_philo *philo)
{
	if (philo->data->n_philo == 1)
	{
		ft_print_status(YELLOW FORK ENDC, philo);
		usleep(philo->data->t_die * 1000);
		ft_print_status(RED DEAD ENDC, philo);
		pthread_mutex_lock(&philo->data->dead);
		philo->data->p_dead = (true);
		pthread_mutex_unlock(&philo->data->dead);
		return (true);
	}
	return (false);
}

void	ft_take_forks(t_philo *philo)
{
	int	fork;

	fork = philo->id % philo->data->n_philo;
	if (philo->id % 2)
	{
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		ft_print_status(YELLOW FORK ENDC, philo);
		pthread_mutex_lock(&philo->data->forks[fork]);
		ft_print_status(YELLOW FORK ENDC, philo);
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[fork]);
		ft_print_status(YELLOW FORK ENDC, philo);
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		ft_print_status(YELLOW FORK ENDC, philo);
	}
}

void	ft_eat(t_philo *philo)
{
	long	start_time;
	long	current_time;

	ft_take_forks(philo);
	pthread_mutex_lock(&philo->data->eating);
	ft_print_status(GREEN EAT ENDC, philo);
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->data->eating);
	start_time = ft_get_time();
	while (1)
	{
		current_time = ft_get_time();
		if (current_time - start_time >= philo->data->t_eat)
			break ;
		if (ft_check_dead(philo))
			break ;
		usleep(100);
	}
	pthread_mutex_lock(&philo->data->eating);
	philo->n_eat++;
	pthread_mutex_unlock(&philo->data->eating);
	pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->n_philo]);
	pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
	ft_print_status(BLUE SLEEP ENDC, philo);
}

void	ft_wait(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->start);
	pthread_mutex_unlock(&philo->data->start);
	if ((philo->id % 2 != 0))
		usleep(4000);
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	long	start_time;
	long	current_time;

	philo = (t_philo *)arg;
	if (ft_one_philo(philo))
		return (NULL);
	ft_wait(philo);
	while (1)
	{
		ft_eat(philo);
		start_time = ft_get_time();
		while (1)
		{
			current_time = ft_get_time();
			if (current_time - start_time >= philo->data->t_sleep)
				break ;
			usleep(4000);
		}
		ft_print_status(THINK, philo);
		if (ft_check_meals(philo) || ft_check_dead(philo))
			break ;
	}
	return (NULL);
}
