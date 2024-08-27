/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:23:36 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/24 14:33:51 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_clean(t_data *data, int option)
{
	int i;

	if (option >= CLEAN_ALL_MUTEXES)
	{
		pthread_mutex_destroy(&data->start);
		pthread_mutex_destroy(&data->print);
		pthread_mutex_destroy(&data->dead);
		pthread_mutex_destroy(&data->eating);
	}
	if (option >= CLEAN_FORK_MUTEXES)
	{
		for (i = 0; i < data->n_philo; i++)
		{
			pthread_mutex_destroy(&data->forks[i]);
		}
	}
	if (option >= CLEAN_FORKS)
		free(data->forks);
	if (option >= CLEAN_PHILOS)
		free(data->philos);
}