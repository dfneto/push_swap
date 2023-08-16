# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davifern <davifern@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 15:56:20 by davifern          #+#    #+#              #
#    Updated: 2023/08/15 15:56:21 by davifern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########################## VARIABLES DEFINITIONS ###############################
NAME = push_swap.a
HEADER = push_swap.h
SRC = movements.c sort_5_less_numbers.c sort_6_more_numbers.c utils_list.c \
		utils_sort_6_more_numbers.c push_swap.c sort_6_more_move_to_b_by_chunks.c \
		utils.c utils_node.c
CFLAGS += -Wextra -Werror -Wall
# This line itself doesn't actually generate the object files; it just sets up the 
# names that will be used when the object files are generated
OBJ = $(SRC:.c=.o)
CC = gcc

################################# RULES ####################################### 
all: $(NAME)

# This pattern rule tells make how to build a .o file from a corresponding .c file 
# (and ensures that the object files are recompiled if the header file, indicated 
# by $(HEADER), changes). It specifies that the command $(CC) $(CFLAGS) -c $< -o $@ 
# should be used to compile each .c file into a corresponding .o file.
# This is a pattern rule that specifies how to build an object file (.o) from a 
# corresponding source file (.c). It also depends on the $(HEADER) file, meaning the
# object files will be recompiled if the header file changes.
# $(CC) $(CFLAGS) -c $< -o $@: This is the command that actually compiles each .c 
# file into an .o file. $< is the first dependency (the .c file in this case) and $@ 
# is the target (the .o file).
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# When you have a rule like $(NAME), the rules put in the same line will be used as 
# mandatory rules. After those rules have been called, the command on the next lines 
# will be called.
# ar -rcs $(NAME) $(OBJ): This command creates the static library $(NAME) (libft.a) 
# from the object files $(OBJ).
$(NAME): $(HEADER) $(OBJ) 
	ar -rcs $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.gch

re: fclean all

.PHONY: all bonus clean fclean re