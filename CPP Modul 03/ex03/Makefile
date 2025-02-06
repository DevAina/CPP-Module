NAME = DiamondTrap

FLAGS = -Wall -Werror -Wextra -Wshadow

C++ = c++

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = ${SRCS:.cpp=.o}

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \33[1;33m
RESET = \033[0m

all : ${NAME}

%.o : %.cpp
	@echo "${YELLOW}Compiling $< ...${RESET}"
	@c++ ${FLAGS} -c $< -o $@

${NAME} : ${OBJS}
	@c++ ${FLAGS} ${OBJS} -o ${NAME}
	@echo "${GREEN}${NAME} has been succesfully built!${RESET}"

clean:
	@echo "${RED}Cleaning object files: ${OBJS}...${RESET}"
	@rm -rf ${OBJS}

fclean : clean
	@echo "\033[36mPerforming full clean ..${RESET}"
	@rm -rf ${NAME}

re : fclean all

.PHONY : all re fclean clean

