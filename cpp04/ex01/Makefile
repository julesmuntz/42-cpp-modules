SRC			=		main.cpp			\
					Animal.cpp			\
					Dog.cpp				\
					Cat.cpp				\
					Brain.cpp			\

OBJDIR		= 		obj/
OBJ			= 		$(addprefix $(OBJDIR), $(SRC:.cpp=.o))

NAME		=		program

CC			=		c++ 
RM			=		rm -f
CPPFLAGS	=		-Wall -Wextra -Werror -std=c++98

$(OBJDIR)%.o:	%.cpp
					@mkdir -p $(@D)
					$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
					$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
					$(RM) -r $(OBJDIR)

fclean:		clean
					$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
