/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:17:26 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/27 12:40:39 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	ft_init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (printf("Error: mutex init\n"), (false));
		i++;
	}
	return (true);
}

bool	ft_init_mutex(t_data *data)
{
	ft_init_forks(data);
	if (pthread_mutex_init(&data->eating, NULL))
		return (printf(MUTEX_ERROR), (false));
	if (pthread_mutex_init(&data->dead, NULL))
		return (printf(MUTEX_ERROR), (false));
	if (pthread_mutex_init(&data->print, NULL))
		return (printf(MUTEX_ERROR), (false));
	if (pthread_mutex_init(&data->start, NULL))
		return (printf(MUTEX_ERROR), (false));
	return (true);
}
