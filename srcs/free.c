/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:23:36 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/27 12:39:08 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_clean(t_data *data, int option)
{
	int	i;

	if (option >= CLEAN_ALL_MUTEXES)
	{
		pthread_mutex_destroy(&data->start);
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->dead);
		pthread_mutex_destroy(&data->eating);
	}
	if (option >= CLEAN_FORK_MUTEXES)
	{
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
	}
	if (option >= CLEAN_FORKS)
		free(data->forks);
	if (option >= CLEAN_PHILOS)
		free(data->philos);
}
