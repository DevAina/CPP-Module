NAME = MutantStack

CXX = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp

OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

%.o : %.cpp
	@echo "\033[1;33mCompiling $< ...\033[0m"
	@${CXX} -c ${FLAGS} $< -o $@

${NAME}: ${OBJS}
	@${CXX} ${FLAGS} ${OBJS} -o ${NAME}
	@echo "\033[1;36m${NAME} has been succesfully built!\033[0m"

clean:
	@echo "\033[1;31mCleaning object files...\033[0m"
	@rm -rf ${OBJS}

fclean : clean
	@echo "\033[1;31mPerforming full clean...\033[0m"
	@rm -rf ${NAME}

re : fclean all

.PHONY: re fclean clean all

