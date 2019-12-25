
CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=\
       -lstdc++\
       -std=c++17
LDFLAGS=\
	-ljsoncpp
$(BIN): $(SRC)
	@$(CC)\
		$(CFLAGS)\
		$(SRC)\
		$(LDFLAGS)\
		-o $(BIN)
.phony:\
	run\
	clean
run:
	@$(BIN)|xxd
clean:
	@rm $(BIN)
