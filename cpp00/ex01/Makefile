SRC			=		main.cpp		\
					Contact.cpp		\

OBJDIR		= 		obj/
OBJ			= 		$(addprefix $(OBJDIR), $(SRC:.cpp=.o))

NAME		=		phonebook

CC			=		c++ 
RM			=		rm -f
CPPFLAGS	=		-Wall -Wextra -Werror -std=c++98

$(OBJDIR)%.o:	%.cpp
					@mkdir -p $(OBJDIR)
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
