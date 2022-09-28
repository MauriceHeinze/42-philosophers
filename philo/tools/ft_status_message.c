/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:59:25 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 13:42:44 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	ft_status_message(t_philosopher *philo, int status_key)
{
	pthread_mutex_lock(&philo->program->allowed_to_print);
	philo->current_time = get_time() - philo->program->started_at;
	if (status_key == IS_DEAD)
		printf("%ld %d died\n", philo->current_time, philo->id);
	if (philo->program->dead == false)
	{
		if (status_key == FORK_TAKEN)
			printf("%ld %d has taken a fork\n", philo->current_time, philo->id);
		else if (status_key == IS_EATING)
			printf("%ld %d is eating\n", philo->current_time, philo->id);
		else if (status_key == IS_SLEEPING)
			printf("%ld %d is sleeping\n", philo->current_time, philo->id);
		else if (status_key == IS_THINKING)
			printf("%ld %d is thinking\n", philo->current_time, philo->id);
	}
	pthread_mutex_unlock(&philo->program->allowed_to_print);
	return (false);
}
