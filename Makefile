CC=gcc

CFLAGS=-Wall -Wextra -Werror -I 

NAME_C=client
NAME_S=server

SRCS_C =	./srcs/client.c \
			./srcs/client_util.c

SRCS_S =	./srcs/server.c \
			./srcs/server_util.c

OBJS_C=$(SRCS_C:.c=.o)
OBJS_S=$(SRCS_S:.c=.o)

INC_C=	./include/client.h
INC_S=	./include/server.h

RM=rm -f

%.c%.o:
	gcc $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(OBJS):	$(INC)


$(NAME): 	$(INC) $(OBJS)
	gcc $(CFLAGS) $(MLX) $(LIBFT) $(PRINT) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all bonus clean fclean re lib