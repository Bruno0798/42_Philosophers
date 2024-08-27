/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 17:51:28 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/27 13:58:18 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	if (!ft_init(argc, argv, &data))
		return (1);
	if (!ft_init_philos(&philos, &data))
		return (ft_clean(&data, CLEAN_PHILOS), 1);
	if (!ft_init_mutex(&data))
		return (ft_clean(&data, CLEAN_ALL_MUTEXES), 1);
	if (!ft_init_threads(&data))
		return (ft_clean(&data, CLEAN_ALL_MUTEXES), 1);
	if (!ft_join_threads(&data))
		return (ft_clean(&data, CLEAN_ALL_MUTEXES), 1);
	ft_clean(&data, CLEAN_ALL_MUTEXES);
	return (0);
}
