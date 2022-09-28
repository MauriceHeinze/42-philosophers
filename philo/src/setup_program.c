/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:29:42 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 13:37:12 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

t_program	*setup_program(int argc, char *argv[])
{
	t_program	*program;

	program = malloc(sizeof(*program));
	if (!program)
		return (NULL);
	program->no_philos = ft_atoi(argv[1]);
	program->time_to_die = ft_atoi(argv[2]);
	program->time_to_eat = ft_atoi(argv[3]);
	program->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		program->times_to_eat = ft_atoi(argv[5]);
	else
		program->times_to_eat = 0;
	program->dead = 0;
	program->started_at = get_time();
	program->no_satisfied_philos = 0;
	pthread_mutex_init(&program->allowed_to_print, NULL);
	program->forks = malloc(sizeof(pthread_mutex_t) * program->no_philos);
	if (!(program->forks))
		return (NULL);
	return (program);
}
