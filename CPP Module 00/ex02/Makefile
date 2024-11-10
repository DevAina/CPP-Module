NAME = Account

FLAGS = -Wall -Werror -Wextra

SRCS = Account.cpp tests.cpp

OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

%.o : %.cpp
	c++ -c ${FLAGS} $< -o $@

${NAME} : ${OBJS}
	c++ ${FLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re: fclean all

.PHONY : all re clean fclean
