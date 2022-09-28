/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_message.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:59:25 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 13:41:48 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

/* Prints error message depending on provided error key */
int	ft_error_message(int error_key)
{
	if (error_key == INVALID_NUMBER_OF_ARGUMENTS)
		printf("Error: invalid number of arguments.\n");
	else if (error_key == INVALID_CHARACTERS_FOUND)
		printf("Error: invalid characters found.\n");
	else if (error_key == INVALID_NUMBER_OF_PHILOSOPHERS)
		printf("Error: invalid number of philosophers.\n");
	else if (error_key == INVALID_TIME_TO_DIE)
		printf("Error: invalid time to die.\n");
	else if (error_key == INVALID_TIME_TO_EAT)
		printf("Error: invalid time to eat.\n");
	else if (error_key == INVALID_TIME_TO_SLEEP)
		printf("Error: invalid time to sleep.\n");
	else if (error_key == INVALID_NUMBER_TIMES_EAT)
		printf("Error: invalid number of times to eat.\n");
	return (false);
}
