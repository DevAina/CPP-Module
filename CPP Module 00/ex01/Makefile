NAME = repertory

CC = c++

FLAGS = -Wall -Wextra -Werror

SRCS = Contact.cpp PhoneBook.cpp repertory.cpp main.cpp utils.cpp

OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

%.o : %.cpp
	${CC} -c ${FLAGS} $< -o $@

${NAME}: ${OBJS}
	c++ ${FLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: re fclean clean all
