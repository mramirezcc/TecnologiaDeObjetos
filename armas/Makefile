CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
TARGET := main
SRC = $(wildcard src/*.cpp)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET)

.PHONY: all clean