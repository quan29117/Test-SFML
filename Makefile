all:
	g++ -Iinclude -Llib -o main main.cpp src/*.cpp -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio
	./main