NAME					=				philo
HEADER					=				philo.h
SRC						=				actions.c		\
										atol.c			\
										clean_philo.c	\
										get_set.c 		\
										philo.c			\
										setup.c			\
										utils.c			\
										the_creator.c	\
										creator_utils.c	\
										print_functions.c			
OBJ						=				$(SRC:%.c=%.o)
FLAGS					=				-Wall -Wextra -Werror

all: $(NAME)

v: all
	valgrind -q --leak-check=full ./philo 4 300 100 100 3

vh: all
	valgrind -q --tool=helgrind ./philo 8 300 100 100 4

vha: all
	valgrind -q --tool=helgrind ./philo $(PHILOS) $(TM_DIE) $(TM_EAT) $(TM_SLEEP) $(AMOUNT_EAT)

va: all
	valgrind -q --leak-check=full ./philo $(PHILOS) $(TM_DIE) $(TM_EAT) $(TM_SLEEP) $(AMOUNT_EAT)

t: all
	./philo $(PHILOS) $(TM_DIE) $(TM_EAT) $(TM_SLEEP) $(AMOUNT_EAT)

$(OBJ): %.o: %.c $(HEADER)
	$(CC) -g3 $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) -g3 $(FLAGS) $(OBJ) -o $(NAME) -pthread

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
