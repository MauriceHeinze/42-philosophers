/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:29:42 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 14:21:24 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	is_lonely(t_philosopher *philo)
{
	if (philo->program->no_philos == 1)
	{
		ft_better_usleep(philo, philo->program->time_to_die);
		ft_status_message(philo, IS_DEAD);
		pthread_mutex_unlock(&philo->program->forks[philo->fork_left]);
		philo->program->dead = true;
		return (true);
	}
	return (false);
}

int	is_dead(t_philosopher *philos, int i)
{
	if ((get_time() - philos[i].ate_at) > philos->program->time_to_die)
	{
		ft_status_message(philos, IS_DEAD);
		philos->program->dead = 1;
		return (1);
	}
	return (0);
}

void	increment_satisfied_philo(t_philosopher *philos, int i)
{
	philos->program->no_satisfied_philos++;
	philos[i].satisfied = 0;
}

int	check_dead(t_philosopher *philos)
{
	int	i;

	i = 0;
	if (is_lonely(philos))
		return (0);
	while (philos->program->dead == 0)
	{
		while (i < philos->program->no_philos)
		{
			if (philos[i].satisfied == 1)
				increment_satisfied_philo(philos, i);
			if (philos[i].ate_at == 0)
				continue ;
			else if (is_dead(philos, i))
				return (0);
			else if (philos->program->no_satisfied_philos
				== philos->program->no_philos)
				return (0);
			i++;
		}
		i = 0;
	}
	return (0);
}
