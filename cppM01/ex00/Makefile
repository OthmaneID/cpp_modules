FILES=newZombie.cpp randomChump.cpp Zombie.cpp main.cpp

OBJ=${FILES:.cpp=.o}

NAME=Zombies

FLAGS=-Wall -Wextra -Werror

all:$(OBJ)
	c++ $(FLAGS) $(OBJ) -o ${NAME}
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all