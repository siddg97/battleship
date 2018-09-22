all: battleship

battleship.o: battleship.cpp
		g++ -c battleship.cpp

player.o: player.cpp
	g++ -c player.cpp

battleship: player.o battleship.o
	g++ -o battleship player.o battleship.o

clean:
	rm -f battleship *.o
