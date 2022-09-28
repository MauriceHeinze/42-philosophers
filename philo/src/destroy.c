/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 19:34:02 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 13:36:04 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	clean_up(t_philosopher *philos)
{
	int				i;
	pthread_mutex_t	*mutex;
	pthread_t		*thread;

	i = 0;
	while (i < philos->program->no_philos)
	{
		mutex = &philos[i].program->forks[i];
		pthread_mutex_destroy(mutex);
		thread = philos[i].thread;
		pthread_join(*thread, NULL);
		i++;
	}
	free(philos);
}
