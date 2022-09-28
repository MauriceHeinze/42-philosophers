CLIENT_NAME = philo
SOURCES = 	./tools/check_dead.c			\
			./tools/ft_atoi.c 				\
			./tools/ft_better_usleep.c		\
			./tools/ft_error_message.c 		\
			./tools/ft_get_time.c 			\
			./tools/ft_is_digit.c			\
			./tools/ft_status_message.c		\
			./tools/ft_valid_input.c 		\
			./src/destroy.c					\
			./src/actions.c					\
			./src/setup_philo.c				\
			./src/setup_program.c			\
			./src/start_threads.c			\

CLIENT = main.c $(SOURCES)

CLIENTOBJ =	$(CLIENT:.c=.o)

HDR = ./incl/philo.h
CC = cc
FLAGS = -g -Wall -Wextra -Werror -fsanitize=address
RM = rm -f

all: $(CLIENT_NAME)
$(CLIENT_NAME): $(HDR) $(CLIENTOBJ)
	$(CC) $(FLAGS) $(CLIENTOBJ) -o $(CLIENT_NAME)

clean:
	$(RM) *.o
	$(RM) */*.o
	$(RM) *.out

fclean: clean
	$(RM) $(CLIENT_NAME)

re:	fclean all

.PHONY: all clean fclean