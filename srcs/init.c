/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:15:15 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/08/24 13:42:52 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	ft_check_values(t_data *data)
{
	if (data->n_philo < 1 || data->n_philo > 200)
		return (printf("Only beetween 1 and 200 philos\n"), (false));
	if (data->t_die < 60 || data->t_eat < 60 || data->t_sleep < 60)
		return (printf("Times cant be lower than 60\n"), (false));
	if (data->n_eat < 0)
		return (printf("Meals\n"), (false));
	return (true);
}

bool	ft_init_struct(int const argc, char **argv, t_data *data)
{
	if(!ft_check_char(argc, argv))
		return (false);
	data->n_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) == 0)
			exit(0);
		data->n_eat = ft_atoi(argv[5]);
	}
	else
		data->n_eat = 0;
	return (true);
}

bool	ft_init(int const argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (printf(ARGS_ERROR), (false));
	if (!ft_init_struct(argc, argv, data))
		return (false);
	if (!ft_check_values(data))
		return (false);
	return (true);
}
