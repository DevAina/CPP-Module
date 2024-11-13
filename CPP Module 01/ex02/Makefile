NAME = reference

FLAGS = -Wall -Werror -Wextra

SRC = main.cpp

OBJ = ${SRC:.cpp=.o}

all : ${NAME}

#Colors
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m

%.o : %.cpp
	echo "${YELLOW}Compiling $< ... ${RESET}"
	@c++ -c ${FLAGS} $< -o $@

${NAME} : ${OBJ}
	@c++ -o ${NAME} ${OBJ} ${FLAGS}
	echo "${CYAN}${NAME} has been succefully built! ${RESET}"

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re: fclean all

.PHONY: re fclean clean all
