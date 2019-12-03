CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
$(BIN): $(SRC)
	@$(CC) $(SRC) -o $(BIN)
.phony:\
	run\
	clean
run:
	@$(BIN)|xxd
clean:
	@rm $(BIN)
