OBJECTS = ./bin/tcpk.o ./bin/os.o
INCLUDES = -I./src

CC = g++
FLAGS = -c -g
CXX = -std=c++17

all: ${OBJECTS}
	$(CC) $(CXX) ./app/main.cpp ${INCLUDES} ${OBJECTS} -g -o ./bin/tcpk

./bin/tcpk.o: ./src/tcpk.cpp
	$(CC) $(CXX) ./src/tcpk.cpp ${INCLUDES} $(FLAGS) -o ./bin/tcpk.o

./bin/os.o: ./src/os/os.cpp
	$(CC) $(CXX) ./src/os/os.cpp ${INCLUDES} $(FLAGS) -o ./bin/os.o


clean:
	rm -rf ./bin/tcpk
	rm -rf ${OBJECTS}