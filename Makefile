CC=gcc

CFLAGS=-Wall -Wextra -Werror

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

all:		$(NAME_C) $(NAME_S)

$(OBJS):	$(INC)


$(NAME_C): 	$(INC_C) $(OBJS_C)
	gcc $(CFLAGS) -I $(INC_C) $(OBJS_C) -o $(NAME_C)

$(NAME_S): 	$(INC_S) $(OBJS_S)
	gcc $(CFLAGS) -I $(INC_S) $(OBJS_S) -o $(NAME_S)

clean:
	$(RM) $(OBJS_C) $(OBJS_S)

fclean: 	clean
	$(RM) $(NAME_S) $(NAME_C)

re:		fclean all

.PHONY: all bonus clean fclean re lib client server