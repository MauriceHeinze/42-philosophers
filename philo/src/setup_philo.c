/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:29:42 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 13:36:49 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

t_philosopher	*setup_philo(int id, t_program *program)
{
	t_philosopher	*philo;

	philo = malloc(sizeof(*philo));
	if (!philo)
		return (NULL);
	philo->thread = malloc((sizeof(pthread_t)));
	if (!philo->thread)
		return (false);
	philo->times_eaten = 0;
	philo->times_eaten = 0;
	philo->ate_at = 0;
	philo->id = id;
	philo->fork_left = id;
	philo->program = program;
	if (program->no_philos - 1 == id)
		philo->fork_right = 0;
	else
		philo->fork_right = id + 1;
	pthread_mutex_init(&(program->forks[id]), NULL);
	return (philo);
}

t_philosopher	*setup_philos(t_program *program)
{
	t_philosopher	*philos;
	int				i;
	int				no_philos;

	philos = malloc((sizeof(t_philosopher) * program->no_philos));
	if (!philos)
		return (NULL);
	i = 0;
	while (i < program->no_philos)
	{
		philos[i] = *setup_philo(i, program);
		i++;
	}
	return (philos);
}
