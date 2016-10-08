
all:LaunchMain

TestSDLCompile: 
	g++ -Wall -g -std=c++11 src/*.cpp -L./lib -I./include -o "main" -lSDL2 -lSDL2main -lpthread -ldl 

LaunchMain: TestSDLCompile
	./main

clean:
	rm main



