NAME = megaphone

FLAGS = -Wall -Werror -Wextra

SRCS = megaphone.cpp

OBJS = ${SRCS:.cpp=.o}

#COLORS
YELLOW = \033[33m
CYAN = \033[36m
RESET = \033[0m	

all	: ${NAME}

%.o : %.cpp
	@ echo "${YELLOW}Compiling $< ... ${RESET}"
	@c++ ${FLAGS} -c $< -o $@

${NAME} : ${OBJS}
	@c++ ${FLAGS} ${OBJS} -o ${NAME}
	@echo "${CYAN}${NAME} has been succefully built! ${RESET}"

clean:
	@echo "\033[31mRemove file objects ...${RESET}"
	@rm -rf ${OBJS}

fclean : clean
	@echo "\033[31mRemove binairie file : ${NAME} ${RESET}"
	@rm -rf ${NAME}

re : fclean all

.PHONY : all fclean re clean
