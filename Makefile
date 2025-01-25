# Compiler dan flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Direktori
SRC = ui
BUILD = build

# Target
TARGET = $(BUILD)/lunar.exe

# File sumber
SOURCES = $(SRC)/main.cpp $(SRC)/install.cpp
OBJECTS = $(patsubst $(SRC)/%.cpp,$(BUILD)/%.o,$(SOURCES))

# Build
all: $(TARGET)

$(TARGET): $(OBJECTS) | $(BUILD)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Buat folder build jika belum ada
$(BUILD):
	mkdir -p $(BUILD)

# Clean up
clean:
	rm -f $(BUILD)/*.o $(TARGET)
	rm -rf $(BUILD)

.PHONY: all clean
