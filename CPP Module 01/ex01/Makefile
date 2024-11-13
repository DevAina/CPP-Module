NAME = zombieHorde

SRCS = main.cpp zombieHorde.cpp Zombie.cpp

OBJS = ${SRCS:.cpp=.o}

FLAGS = -Wall -Werror -Wextra

all : ${NAME}

%.o : %.cpp
	c++ ${FLAGS} -c $< -o $@

${NAME} : ${OBJS}
	c++ ${FLAGS} ${OBJS} -o ${NAME}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY : all re fclean clean
