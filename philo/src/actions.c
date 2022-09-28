/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:29:42 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 14:21:01 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->program->forks[philo->fork_left]);
	ft_status_message(philo, FORK_TAKEN);
	pthread_mutex_lock(&philo->program->forks[philo->fork_right]);
	ft_status_message(philo, FORK_TAKEN);
}

void	eat(t_philosopher *philo)
{
	ft_status_message(philo, IS_EATING);
	philo->ate_at = get_time();
	ft_better_usleep(philo, philo->program->time_to_eat);
	pthread_mutex_unlock(&philo->program->forks[philo->fork_right]);
	pthread_mutex_unlock(&philo->program->forks[philo->fork_left]);
}

void	philo_sleep(t_philosopher *philo)
{
	ft_status_message(philo, IS_SLEEPING);
	ft_better_usleep(philo, philo->program->time_to_sleep);
}

void	think(t_philosopher *philo)
{
	ft_status_message(philo, IS_THINKING);
}
