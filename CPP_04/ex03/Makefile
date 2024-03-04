NAME      = AMateria

OBJ_DIR   = objs

CPP       = c++

SRC_DIR   = srcs

INC_DIR   = includes

SRCS      = $(SRC_DIR)/main.cpp \
            $(SRC_DIR)/AMateria.cpp \
            $(SRC_DIR)/Character.cpp \
            $(SRC_DIR)/Cure.cpp \
            $(SRC_DIR)/Ice.cpp \
            $(SRC_DIR)/MateriaSource.cpp

OBJS      = $(addprefix $(OBJ_DIR)/,$(notdir $(SRCS:.cpp=.o)))

CPPFLAGS  = -Wall -Werror -Wextra -std=c++98 -I$(INC_DIR)

RM        = rm -rf

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJS)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CPP) $(CPPFLAGS) -c -o $@ $<

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

r: re
	@valgrind ./$(NAME)