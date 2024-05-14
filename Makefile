# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtorrett <dtorrett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/12 13:48:56 by dtorrett          #+#    #+#              #
#    Updated: 2024/05/12 13:48:56 by dtorrett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SOURCES = server.c client.c errors.c
OBJECTS = $(SOURCES:.c=.o)
LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: libft server client 

libft:
	make -C libft
#'-C': changes the directory before executing the make command

server: server.o $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "\n------------------------------------------\n"
	@echo "📥 Server ready!\n"
	@echo "------------------------------------------\n"
	
client: client.o errors.c $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "\n------------------------------------------\n"
	@echo "📟 Client ready!\n"
	@echo "------------------------------------------\n"
	
#' $^ ': represents all the prerequisites (object files, Libmlx and the libft library)
#' $@ ': represents the target, which is the name of the executable


%.o: %.c
	$(CC) $(CFLAGS) -I libft -I . -c $< -o $@

#example: for 'serve.o' the command would be: $(CC) $(CFLAGS) -I libft -I . -c server.c -o server.o.
#'-I libft': flag used to specifies an additional directory to include header files from. In this case, it includes header files from the libft directory.
#'-I .': flag used to include the current directory as a directory to search for header files. The dot (.) represents the current directory.
#'-c': flag used to tell the compiler to generate object files (*.o) without linking.
#'$<': this is an automatic variable that represents the first prerequisite (dependency) of the rule. It typically represents the source file (*.c).
#'-o $@': flag used to specify the output file name. The output will have the same name that the target of the rule + (*.o extension)
#'-c $< -o $@': command to compile the source files (*.c) into object files (*.o) without performing linking. 

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C libft clean
	@echo "\n------------------------------------------\n"
	@echo "💧 Clean: Removed all the \".o\" files \n"
	@echo "------------------------------------------\n"
	
fclean: clean
	@rm -f server client libft/libft.a
	@echo "------------------------------------------\n"
	@echo "🧼 Fclean: Removed the executables \n"
	@echo "------------------------------------------\n"
	
re: fclean all

.PHONY: all bonus libft clean fclean re