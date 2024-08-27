/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:18:27 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/27 13:53:16 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_waiter(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->n_philo)
		{
			if (ft_check_meals(&data->philos[i]))
				return ;
			pthread_mutex_lock(&data->eating);
			if (ft_get_time() - data->philos[i].last_meal >= data->t_die)
			{
				ft_print_status(RED DEAD ENDC, &data->philos[i]);
				pthread_mutex_lock(&data->dead);
				data->p_dead = (true);
				pthread_mutex_unlock(&data->dead);
				pthread_mutex_unlock(&data->eating);
				return ;
			}
			pthread_mutex_unlock(&data->eating);
			i++;
		}
	}
}

bool	ft_init_threads(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->start);
	while (i < data->n_philo)
	{
		data->philos[i].last_meal = ft_get_time();
		data->philos[i].n_eat = 0;
		if (pthread_create(&data->philos[i].thread, NULL,
				ft_routine, &data->philos[i]))
			return (printf("Error: thread create\n"), (false));
		i++;
	}
	data->time = ft_get_time();
	pthread_mutex_unlock(&data->start);
	ft_waiter(data);
	return (true);
}

bool	ft_init_philos(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	*philos = (t_philo *)malloc(sizeof(t_philo) * data->n_philo);
	if (!*philos)
		return (printf(MALLOC_ERROR), (false));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->n_philo);
	if (!data->forks)
		return (printf(MALLOC_ERROR), free(philos), false);
	while (i < data->n_philo)
	{
		memset((void *)&(*philos)[i], 0, sizeof(t_philo));
		(*philos)[i].id = i + 1;
		(*philos)[i].n_eat = 0;
		(*philos)[i].last_meal = 0;
		(*philos)[i].data = data;
		i++;
	}
	data->philos = *philos;
	return (true);
}

bool	ft_join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL))
			return (printf("Error: thread join\n"), (false));
		i++;
	}
	return ((true));
}
