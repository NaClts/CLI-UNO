.PHONY: all clean directories

NAME = hkuno
BIN_DIR = bin
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
DIRS = $(BIN_DIR) $(BUILD_DIR) $(SRC_DIR) $(INCLUDE_DIR)

all: directories $(NAME)

$(NAME): $(BIN_DIR)/$(NAME)

$(BIN_DIR)/$(NAME): $(BUILD_DIR)/AI_requestAI.o $(BUILD_DIR)/SaveAndLoad.o $(BUILD_DIR)/card_effect.o $(BUILD_DIR)/selfDefStruct.o $(BUILD_DIR)/random.o
	$(CXX) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -I$(INCLUDE_DIR) -c $< -o $@

directories: $(DIRS)

$(DIRS):
	mkdir -p $@

clean:
	rm -rf $(DIRS)
