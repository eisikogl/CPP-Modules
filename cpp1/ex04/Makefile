NAME = SedIsForLosers

CC = c++ -std=c++98
CFLAGS = -Wall -Werror -Wextra

SRC = $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJ)	testfile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

testfile:
	@echo "Im not a cat in a box im a cat in a hat" > testfile

clean:
	@find . -name "*.o" -delete
	@find . -name "testfile.replace" -delete
	@echo "Cleaning"

fclean: clean
	@rm $(NAME)
	@rm testfile
	@echo "Done"

re: fclean all