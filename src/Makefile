CC=g++
CFLAGS=-Wall -pedantic -std=c++11
SRC=Utilities.cpp Cli.cpp Dictionary.cpp main.cpp
OBJS=$(SRC:.cpp=.o)
EXEC=search_word

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^


%.o: %.h %.cpp
	$(CC) $(CFLAGS) -c $^

Dictionary.o : WordsDictionary.h

clean:
	rm -rf *.o $(EXEC) 

