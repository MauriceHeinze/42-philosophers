/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:22:51 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 13:31:54 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./incl/philo.h"

int	main(int argc, char *argv[])
{
	t_program		*program;
	t_philosopher	*philos;

	if (!ft_valid_input(argc, argv))
		return (0);
	else
	{
		program = setup_program(argc, argv);
		philos = setup_philos(program);
		start_all_philos(philos);
		check_dead(philos);
		clean_up(philos);
	}
	return (0);
}
