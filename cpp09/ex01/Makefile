NAME = RPN
CC = c++
CXXFLAGS = -Wall -Werror -Wextra
SRCS =	main.cpp \
		RPN.cpp

OBJS = ${SRCS:.cpp=.o}

.c.o:
	${CC} ${CXXFLAGS} ${INC} -g3 -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) $(LIB) -o $(NAME)

debug: $(OBJS)
	$(CC) $(CXXFLAGS) -fsanitize=address $(OBJS) $(LIB) -o $(NAME)

c98: $(OBJS)
	$(CC) $(CXXFLAGS) -std=c++98 $(OBJS) $(LIB) -o $(NAME)

all: $(NAME)

bonus: all

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean