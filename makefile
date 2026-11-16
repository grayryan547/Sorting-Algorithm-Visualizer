CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Iinclude

SRC = src/main.cpp src/utils.cpp src/sorts.cpp src/visualizer.cpp
TARGET = sorter

all: $(TARGET)

$(TARGET): $(SRC)
    $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
    rm -f $(TARGET) $(TARGET).exe