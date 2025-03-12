NAME = BureaucratForm

FLAGS = -Wall -Werror -Wextra -g -std=c++98

SRCS = main.cpp Bureaucrat.cpp AForm.cpp  ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp PresidentialPardonForm.cpp

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
