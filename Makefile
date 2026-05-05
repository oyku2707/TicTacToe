all: compile link

compile:
	g++ -std=c++17 -I/opt/homebrew/opt/sfml/include -c src/main.cpp -o main.o

link:
	g++ main.o -o main -L/opt/homebrew/opt/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm -f main.o main