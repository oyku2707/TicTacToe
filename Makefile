CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -I/opt/homebrew/opt/sfml/include
SFML_LIBS = -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = src/main.cpp src/oyuncuSecimi.cpp src/oyunMekanigi.cpp src/oyunArayuzu.cpp src/oyunTahtasi.cpp src/yapayZeka.cpp

TARGET = main

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(SFML_LIBS)
clean:
	rm -f $(TARGET)