# Derleyici ve Standart
CXX = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/opt/sfml/include

# SFML Kütüphaneleri (Mac/Homebrew için)
LDFLAGS = -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

# Dosya Yolları
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = main

# Varsayılan Kural
all: $(TARGET)

# Bağlama (Linking)
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Derleme (Compiling)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Temizlik
clean:
	rm -f $(SRC_DIR)/*.o $(TARGET)