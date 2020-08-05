CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=\
       -lstdc++\
       -std=c++11
LDFLAGS=-pthread
$(BIN): $(SRC)
	@$(CC)\
		$(CFLAGS)\
		$(SRC)\
		$(LDFLAGS)\
		-o $(BIN)
.phony:\
	run\
	clean
run:$(BIN)
	@/usr/bin/time $(BIN) 0
	@/usr/bin/time $(BIN) 1
clean:
	@rm $(BIN)
