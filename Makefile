program: main.o
	g++ -std=c++11 main.o -o networkmap
main.o:	
	g++ -std=c++11 -c main.cpp -o main.o

