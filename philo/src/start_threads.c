/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:29:42 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 14:21:16 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	*philo_life(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	philo->started_at = get_time();
	if (philo->id % 2 != 0)
		ft_better_usleep(philo, philo->program->time_to_eat);
	while (philo->program->dead == 0)
	{
		take_forks(philo);
		eat(philo);
		philo->times_eaten++;
		if (philo->program->times_to_eat > 0)
		{
			if (philo->times_eaten == philo->program->times_to_eat)
			{
				philo->satisfied = 1;
				break ;
			}
		}
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

bool	start_philo_life(t_philosopher *philo)
{
	if (pthread_create
		(&(*philo->thread), NULL, philo_life, (void *)philo) != 0)
		return (false);
	return (true);
}

bool	start_all_philos(t_philosopher *philo)
{
	int	i;
	int	no_philos;

	i = 0;
	no_philos = philo->program->no_philos;
	while (i < no_philos)
	{
		if (!start_philo_life(&philo[i]))
			return (false);
		i++;
	}
	return (true);
}
