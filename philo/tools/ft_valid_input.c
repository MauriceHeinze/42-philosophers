/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:55:06 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/21 00:07:48 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

static int	found_no_negative(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (ft_error_message(INVALID_NUMBER_OF_ARGUMENTS));
	if (ft_atoi(argv[1]) < 1)
		return (ft_error_message(INVALID_NUMBER_OF_PHILOSOPHERS));
	if (ft_atoi(argv[2]) < 1)
		return (ft_error_message(INVALID_TIME_TO_DIE));
	if (ft_atoi(argv[3]) < 1)
		return (ft_error_message(INVALID_TIME_TO_EAT));
	if (ft_atoi(argv[4]) < 1)
		return (ft_error_message(INVALID_TIME_TO_SLEEP));
	if (argc == 6)
		if (ft_atoi(argv[5]) < 1)
			return (ft_error_message(INVALID_NUMBER_TIMES_EAT));
	return (true);
}

int	ft_valid_input(int argc, char *argv[])
{
	int	i;
	int	k;

	i = 1;
	if (!found_no_negative(argc, argv))
		return (false);
	while (i < argc)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (!ft_is_digit(argv[i][k]))
				return (ft_error_message(INVALID_CHARACTERS_FOUND));
			k++;
		}
		i++;
	}
	return (true);
}
