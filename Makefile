CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -I./include
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN = $(BUILD_DIR)/sls
FORMATTER = clang-format

SRC = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(INC_DIR)/*.hpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

all: $(BIN)

$(BIN): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

run: all
	./$(BIN)

format:
	$(FORMATTER) -i $(SRC) $(HEADERS)

.PHONY: all clean run format

