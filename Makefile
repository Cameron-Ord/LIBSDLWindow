all:
	g++ -std=c++11 -Iinclude -o bin/main src/main.cpp src/RenderWindow.cpp -lSDL2 -lSDL2_image