# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qestefan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 12:27:45 by qestefan          #+#    #+#              #
#    Updated: 2021/07/14 12:40:40 by qestefan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIST	=	${wildcard src/*.c}

OBJ		=	${LIST:.c=.o}

INC		=	header

FLAGS	=	-Wall -Werror -Wextra

NAME	=	bsq

.c.o:
	gcc ${FLAGS} -c $< -o ${<:.c=.o} -I ${INC}

all: ${NAME}

${NAME}:${OBJ}
	gcc ${FLAGS} ${OBJ} -o ${NAME} -I {INC}

clean:
	rm -f ${OBJ}

flean: clean
	rm -f ${NAME}

re: fclean all
