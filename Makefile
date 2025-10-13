CC=gcc
CFLAGS=-Wall --pedantic
BIN=./bin
SRC=./src
TESTDIR=./tests

all: $(BIN)/exercise1 $(BIN)/exercise2 $(BIN)/exercise3 $(BIN)/exercise4 $(BIN)/exercise5

$(BIN)/exercise1: bin
	$(CC) $(CFLAGS) $(SRC)/exercise1.c -o $(BIN)/exercise1 -lm  # ← ДОБАВЬ -lm ЗДЕСЬ
	
$(BIN)/exercise2: bin
	$(CC) $(CFLAGS) $(SRC)/exercise2.c -o $(BIN)/exercise2

$(BIN)/exercise3: bin
	$(CC) $(CFLAGS) $(SRC)/exercise3.c -o $(BIN)/exercise3

$(BIN)/exercise4: bin
	$(CC) $(CFLAGS) $(SRC)/exercise4.c -o $(BIN)/exercise4

$(BIN)/exercise5: bin
	$(CC) $(CFLAGS) $(SRC)/exercise5.c -o $(BIN)/exercise5

test1: $(BIN)/exercise1
	$(TESTDIR)/test1.sh

test2: $(BIN)/exercise2
	$(TESTDIR)/test2.sh

test3: $(BIN)/exercise3
	$(TESTDIR)/test3.sh

test4: $(BIN)/exercise4
	$(TESTDIR)/test4.sh

test5: $(BIN)/exercise5
	$(TESTDIR)/test5.sh

bin:
	mkdir $(BIN)

clean:
	rm -rf $(BIN)
