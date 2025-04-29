# Compilation
CC					=	c++
CFLAGS				=	-Wall -Wextra -Werror -std=c++98

# Names
NAME				=	form

# Sources & Includes
SRCS				= 	main.cpp \
						Bureaucrat.cpp \
						Form.cpp
OBJ_FOLDER			=	objs

# Objects
OBJS				=	$(patsubst %.cpp, $(OBJ_FOLDER)/%.o, $(SRCS))

# Custom Makefile Flags
MAKEFLAGS			+=	--no-print-directory --silent

# Custom Colors
PURPLE				=	\033[1;35m
LIGHT_GREEN			=	\033[1;32m
RESET				=	\033[0m

# Custom messages
EXE_DONE			=	@echo "🎉$(PURPLE) $(NAME) compiled! 🎉$(RESET)\n"
ALL_CLEAN			=	@echo "🧹$(LIGHT_GREEN) Project's objects cleaned! 🧹$(RESET)\n"
ALL_FCLEAN			=	@echo "🧹$(LIGHT_GREEN) Project's objects & Executables cleaned! 🧹$(RESET)\n"

# Rules

all : check_relink

check_relink:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir $(OBJ_FOLDER); \
	fi
	@if [ -f $(NAME) ]; then \
		echo '✅$(LIGHT_GREEN) Nothing to be done for "all"! ✅$(RESET)\n'; \
	else \
		$(MAKE) $(NAME); \
	fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	$(EXE_DONE)

$(OBJ_FOLDER)/%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ_FOLDER)
	$(ALL_CLEAN)

fclean :
	@rm -f $(NAME)
	@rm -rf $(OBJ_FOLDER)
	$(ALL_FCLEAN)

re : fclean all

.PHONY: all clean fclean re
