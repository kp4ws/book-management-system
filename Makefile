# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Werror -std=c++11

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Include directories
INCLUDES = -I $(INCLUDE_DIR)

# Target executable
TARGET = $(BIN_DIR)/app

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Run program
run: all
	./$(TARGET)

# Clean rule (removes object files but does not delete the executable)
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET) 