# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
LDFLAGS =

# Directories
SRC_DIR = ui
INC_DIR = include
BUILD_DIR = build
LOG_DIR = log

# Source files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Target executable
TARGET = lunar.exe

# Default rule
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR) $(LOG_DIR)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Create log directory if it doesn't exist
$(LOG_DIR):
	mkdir -p $(LOG_DIR)

# Clean build and log files
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	rm -rf $(LOG_DIR)/*.log

# Clean logs only
clean_logs:
	rm -rf $(LOG_DIR)/*.log

# Phony targets
.PHONY: all clean clean_logs debug
