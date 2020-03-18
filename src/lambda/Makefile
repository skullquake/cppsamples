CC=g++
SRC=./src/a.cpp
BIN=./bin/a.out
CFLAGS=\
       -lstdc++\
       -std=c++17
LDFLAGS=
$(BIN): $(SRC)
	@mkdir -p $(@D)
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
