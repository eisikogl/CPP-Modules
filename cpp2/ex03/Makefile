NAME 		= Fixed

SRCS		= main.cpp \
				Fixed.cpp \
				Point.cpp \
				bsp.cpp 

OBJS		= $(SRCS:.cpp=.o)

CPP			= c++ -std=c++98
CPPFLAGS	= -Wall -Werror -Wextra

all:		$(OBJS)
			$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
			
clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re