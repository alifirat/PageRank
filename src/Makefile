CC=g++
CFLAGS=-Wall -pedantic -std=c++11
SRC=Utilities.cpp MarkovMatrix.cpp main.cpp
OBJS=$(SRC:.cpp=.o)		
EXEC=search_word

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

main.o: main.cpp
	$(CC) $(CFLAGS) -c $^


%.o: %.h %.cpp
	$(CC) $(CFLAGS) -c $^

main.o : ListDictionary.h

clean:
	rm -rf *.o *.h.gch $(EXEC)  *~

