CC = g++
CFLAGS = -Wall -g

proj3: main.o functions.o
	$(CC) $(CFLAGS) -o proj3 main.o functions.o

main.o: main.cpp functions.h
	$(CC) $(CFLAGS) -c main.cpp

functions.o: functions.h
	$(CC) $(CFLAGS) -c functions.cpp

clean:
	rm *.o proj3