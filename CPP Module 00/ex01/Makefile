NAME = repertory

CC = c++

FLAGS = -Wall -Wextra -Werror

SRCS = Contact.cpp PhoneBook.cpp repertory.cpp main.cpp utils.cpp

OBJS = ${SRCS:.cpp=.o}

all : ${NAME}

%.o : %.cpp
	@echo "\033[33mCompiling $< ...\033[0m"
	@${CC} -c ${FLAGS} $< -o $@

${NAME}: ${OBJS}
	@c++ ${FLAGS} ${OBJS} -o ${NAME}
	@echo "\033[36m${NAME} has been succesfully built!\033[0m"

clean:
	@echo "\033[31mCleaning object files...\033[0m"
	@rm -rf ${OBJS}

fclean : clean
	@echo "\033[31mPerforming full clean...\033[0m"
	@rm -rf ${NAME}

re : fclean all

.PHONY: re fclean clean all
