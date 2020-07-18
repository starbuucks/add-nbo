all: add_nbo
	
add_nbo: sum.o main.o
	g++ -o add_nbo sum.o main.o

sum.o: sum.h sum.cpp
	g++ -c -o sum.o sum.cpp

main.o: main.cpp sum.h
	g++ -c -o main.o main.cpp

clean:
	rm -f add_nbo *.o
