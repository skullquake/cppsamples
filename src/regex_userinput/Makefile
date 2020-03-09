CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=\
       -lstdc++\
       -std=c++17
$(BIN): $(SRC)
	@$(CC)\
		$(CFLAGS)\
		$(SRC)\
		-o $(BIN)
.phony:\
	run\
	clean
run:
	@$(BIN)
clean:
	@rm $(BIN)
