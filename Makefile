NAME		=	npuzzle

FLAGS		=	-std=c++11 -Wall -Wextra -Werror -O3

LNXFLAGS	=	-lbsd

SRCDIR		=	srcs/

INCDIR		=	includes/

OBJDIR		=	objs/

SRC			=	main.cpp \
				Solver.cpp \
				NodeTool.cpp \
				Node.cpp \
				Manhattan.cpp \
				Nothing.cpp \
				LinearConflict.cpp \
				Parser.cpp \
				MisplacedTiles.cpp \
				CreateHeuristic.cpp


SRCS =	$(addprefix $(SRCDIR), $(SRC))

OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

UNAME := $(shell uname)

all:		$(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@mkdir -p $(dir $(OBJ))

$(OBJDIR)%.o : $(SRCDIR)%.cpp | $(OBJDIR)
ifeq ($(UNAME), Linux)
	g++ $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LNXFLAGS)
else
	g++ $(FLAGS) -c $< -o $@ -I $(INCDIR)
endif


$(NAME):	$(OBJDIR) $(OBJ)
ifeq ($(UNAME), Linux)
	g++ $(FLAGS) -o $(NAME) $(OBJ) $(LNXFLAGS)
else
	g++ $(FLAGS) -o $(NAME) $(OBJ)
endif

clean:
	if [ -d $(OBJDIR) ]; then rm -r $(OBJDIR); fi

fclean:	clean
	@rm -f $(NAME)

re:	fclean all


.PHONY: fclean clean re 

.SILENT: clean
