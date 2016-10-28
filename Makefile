
all:LaunchNampac

Nampac-Compile: 
	g++ -Wall -g -std=c++11 src/*.cpp -L./lib -I./include -o "Nampac" -lSDL2 -lSDL2main -lSDL2_ttf -lpthread -ldl -lfreetype

LaunchNampac: Nampac-Compile
	./Nampac

clean:
	rm Nampac



