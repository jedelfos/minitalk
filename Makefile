CC=gcc

CFLAGS=-Wall -Wextra -Werror

NAME_C=client
NAME_S=server

SRCS_C =	./srcs/client.c

SRCS_S =	./srcs/server.c

OBJS_C=$(SRCS_C:.c=.o)
OBJS_S=$(SRCS_S:.c=.o)

INC_C=	./include/client.h
INC_S=	./include/server.h

RM=rm -f

%.c%.o:
	gcc $(CFLAGS) -c $< -o $@

all:		$(NAME_C) $(NAME_S)

$(OBJS_C):	$(INC_C)
$(OBJS_S):	$(INC_S)

$(NAME_C): $(OBJS_C) $(INC_S)
	@gcc $(CFLAGS) -I $(INC_C) $(OBJS_C) -o $(NAME_C)

$(NAME_S): $(OBJS_S) $(INC_S)
	@gcc $(CFLAGS) -I $(INC_S) $(OBJS_S) -o $(NAME_S)

clean:
	$(RM) $(OBJS_C) $(OBJS_S)

fclean: 	clean
	$(RM) $(NAME_S) $(NAME_C)

re:		fclean all

.PHONY: all bonus clean fclean re lib client server