OBJECTS = ./bin/os.o
INCLUDES = -I./src

CC = g++
FLAGS = -c -g

all: ${OBJECTS}
	$(CC) ./src/main.cpp ${INCLUDES} ${OBJECTS} -g -o ./bin/tcpk

./bin/os.o: ./src/os/os.cpp
	$(CC) ./src/os/os.cpp ${INCLUDES} $(FLAGS) -o ./bin/os.o


clean:
	rm -rf ./bin/tcpk
	rm -rf ${OBJECTS}