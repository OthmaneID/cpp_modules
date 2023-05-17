FILES = tests.cpp Account.cpp

OBJ=$(FILES:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

NAME = Account

all: ${OBJ}
	c++  ${OBJ} ${CFLAGS} -o ${NAME}
clean :
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re : fclean all