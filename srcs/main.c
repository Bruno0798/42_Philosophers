/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:51:28 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/24 14:34:11 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (!ft_init(argc, argv, &data)
		return (1);
	if (!ft_init_philos(&philos, &data))
		return (ft_clean(&data, CLEAN_PHILOS), 1);
	if (!ft_init_mutex(&data))

	|| !ft_init_threads(&data)
		|| !ft_join_threads(&data))
		return (1);
	ft_clean(&data, CLEAN_ALL_MUTEXES);
	return (0);
}
