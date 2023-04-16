SRC			=		main.cpp			\
					$(addprefix source/,\
					AMateria.cpp		\
					Ice.cpp				\
					Cure.cpp			\
					Character.cpp		\
					MateriaSource.cpp	\
					)					\

OBJDIR		= 		.obj/
OBJ			= 		$(addprefix $(OBJDIR), $(SRC:.cpp=.o))

NAME		=		program

CC			=		c++ 
RM			=		rm -f
CPPFLAGS	=		-Wall -Wextra -Werror -g -std=c++98 -Iheaders

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
