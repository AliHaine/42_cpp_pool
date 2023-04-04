NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra
SRCS =	Account.cpp \
		tests.cpp

OBJS = ${SRCS:.cpp=.o}

.c.o:
	${CC} ${CFLAGS} ${INC} -g3 -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

debug: $(OBJS)
	$(CC) $(CFLAGS) -fsanitize=address $(OBJS) $(LIB) -o $(NAME)

all: $(NAME)

bonus: all

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean