/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinze <mheinze@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:05:26 by mheinze           #+#    #+#             */
/*   Updated: 2022/09/28 14:21:40 by mheinze          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_program {
	int						no_philos;
	int						no_satisfied_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						times_to_eat;
	int						dead;
	long					started_at;
	pthread_mutex_t			*forks;
	pthread_mutex_t			allowed_to_print;
}				t_program;

typedef struct s_philosopher {
	pthread_t				*thread;
	int						satisfied;
	int						fork_left;
	int						fork_right;
	int						id;
	int						times_eaten;
	long					started_at;
	long					current_time;
	long					ate_at;
	struct s_program		*program;
}				t_philosopher;

// TOOLS
int				ft_atoi(const char *nptr);
int				ft_valid_input(int argc, char **argv);
long			get_time(void);
bool			ft_is_digit(char c);
void			ft_better_usleep(t_philosopher *philo, long delay_ms);
int				check_dead(t_philosopher *philos);

// SETUP
// setup_progam.c
t_program		*setup_program(int argc, char *argv[]);

// setup_philo.c
t_philosopher	*setup_philo(int id, t_program *program);
t_philosopher	*setup_philos(t_program *program);

// start_threads.c
void			*philo_life(void *data);
bool			start_philo_life(t_philosopher *philo);
bool			start_all_philos(t_philosopher *philo);

// action.c
void			take_forks(t_philosopher *philo);
void			eat(t_philosopher *philo);
void			philo_sleep(t_philosopher *philo);
void			think(t_philosopher *philo);

// destroy
void			clean_up(t_philosopher *philos);

// ERROR HANDLING
# define INVALID_CHARACTERS_FOUND 		1
# define INVALID_NUMBER_OF_ARGUMENTS 	2
# define INVALID_NUMBER_OF_PHILOSOPHERS 3
# define INVALID_TIME_TO_DIE 			4
# define INVALID_TIME_TO_EAT 			5
# define INVALID_TIME_TO_SLEEP 			6
# define INVALID_NUMBER_TIMES_EAT 		7

// STATUS KEYS
# define FORK_TAKEN		8
# define IS_EATING		9
# define IS_SLEEPING	10
# define IS_THINKING	11
# define IS_DEAD		12
# define FREE			13

// messages
int				ft_error_message(int error_key);
int				ft_status_message(t_philosopher *philo, int status_key);

#endif
