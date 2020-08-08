CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=\
       -std=c++11
LDFLAGS=\
	-lpthread
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
	@$(BIN)
clean:
	@rm $(BIN)
