FILES = main.cpp PhoneBook.cpp Contacts.cpp

OBJ=$(FILES:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

NAME = PhoneBook

all: ${OBJ}
	c++  ${OBJ} ${CFLAGS} -o ${NAME}
clean :
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re : fclean all