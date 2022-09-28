/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_usleep.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:11:03 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 14:20:10 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	ft_better_usleep(t_philosopher *philo, long delay_ms)
{
	struct timeval	now;
	struct timeval	start;
	long			i;

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	i = 0;
	while (i < delay_ms && philo->program->dead == 0)
	{
		gettimeofday(&now, NULL);
		i = ((now.tv_sec - start.tv_sec) * 1000)
			+ ((now.tv_usec - start.tv_usec) / 1000);
		usleep(333);
	}
}
