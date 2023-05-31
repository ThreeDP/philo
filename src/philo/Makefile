NAME					=				philo
HEADER					=				philo.h
SRC						=				philo.c utils.c
OBJ						=				$(SRC:%.c=%.o)
FLAGS					=				-Wall -Wextra -Werror

all: $(NAME)

$(OBJ): %.o: %.c $(HEADER)
	$(CC) -g3 $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) -g3 $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all