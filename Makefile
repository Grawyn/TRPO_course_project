.PHONY: clean game
SS = g++
SSFLAGS = -Wall -Werror -std=c++11
SR = src/
TRD = thirdparty/
BUL = build/
BIN = bin/
BUL_TEST = build/test/
all: $(BIN)game

$(BIN)game: $(BUL)main.o $(BUL)logic.o
	$(SS) -o $(BIN)game $(BUL)main.o $(BUL)logic.o

$(BUL)main.o: $(SR)main.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)main.cpp -o $(BUL)main.o

$(BUL)logic.o: $(SR)logic.cpp
	$(SS) $(SSFLAGS) -I $(SR) -c $(SR)logic.cpp -o $(BUL)logic.o

clean:
	rm -rf $(BUL)*.o
	rm -rf $(BIN)game
run:
	$(BIN)game