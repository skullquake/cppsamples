CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
$(BIN): $(SRC)
	$(CC) $(SRC) -o $(BIN)
.phony:\
	clean\
	run
run:
	$(BIN)
clean:
	rm $(BIN)
