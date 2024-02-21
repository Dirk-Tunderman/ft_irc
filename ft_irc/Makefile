NAME = server
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc
SRC_DIR = src
SRV_DIR = $(SRC_DIR)/server
INC_DIR = inc
OBJ_DIR = obj
SRC = $(SRV_DIR)/init.cpp $(SRC_DIR)/main.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
vpath %.cpp $(SRC_DIR):$(SRV_DIR)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@
	mkdir -p $(OBJ_DIR)/server

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re