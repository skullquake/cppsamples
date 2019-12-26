CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=\
       -lstdc++\
       -std=c++17
LDFLAGS=
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
	@echo 123|$(BIN)
clean:
	@rm $(BIN)
