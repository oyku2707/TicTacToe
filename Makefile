CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/opt/sfml/include -I./include
LDFLAGS = -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

SRC = src/main.cpp src/oyunMekanigi.cpp src/oyuncuSecimi.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f src/*.o $(TARGET)