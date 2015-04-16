CC=g++
CFLAGS=-Wall -pedantic -std=c++11
OBJS=main.o Utilities.o Cli.o Dictionary.o
EXEC=search_word

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^


%.o: src/%.cpp src/%.h
	$(CC) $(CFLAGS) -c $^

.cpp.o:
	$(CC) 
clean:
	rm -rf *.o src/*.o $(EXEC) 

