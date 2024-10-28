# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhyulee <juhyulee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 18:16:25 by juhyulee          #+#    #+#              #
#    Updated: 2023/01/10 17:25:43 by juhyulee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SRCS_S = server.c
SRCS_C = client.c

OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : 		$(SERVER) $(CLIENT)

$(SERVER) :	$(OBJS_S)
			$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_S)

$(CLIENT) :	$(OBJS_C)
			$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_C)

clean :
			$(RM) $(OBJS_S) $(OBJS_C)

fclean :	clean
			$(RM) $(SERVER) $(CLIENT)

re :		fclean all

.PHONY : all clean fclean re
