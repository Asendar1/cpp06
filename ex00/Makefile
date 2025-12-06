SRC_FILES = ScalarConverter.cpp main.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
CXX = c++ -Wall -Wextra -Werror -std=c++98
NAME = scalar_converter

all: $(NAME)

$(NAME): $(SRC_FILES)
	$(CXX) $(SRC_FILES) -I. -o $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
