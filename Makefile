CC=gcc
CFLAGS=-Wall --pedantic -Wextra -std=c99
BIN=./bin
SRC=./src
TESTDIR=./tests
EXTRA=./extra

TARGET1 = test_runner1
TARGET2 = test_runner2
TARGET3 = test_runner3

$(TARGET1): $(SRC)/advanced_array_function.c $(TESTDIR)/test_max_sum_array.c $(EXTRA)/Unity/unity.c $(BIN)
	$(CC) $(CFLAGS) $(SRC)/advanced_array_function.c \
	$(TESTDIR)/test_max_sum_array.c \
	$(EXTRA)/Unity/unity.c -o $(BIN)/$(TARGET1)

$(TARGET2): $(SRC)/advanced_array_function.c $(TESTDIR)/test_longest_increasing_subsequence.c $(EXTRA)/Unity/unity.c $(BIN)
	$(CC) $(CFLAGS) $(SRC)/advanced_array_function.c \
	$(TESTDIR)/test_longest_increasing_subsequence.c \
	$(EXTRA)/Unity/unity.c -o $(BIN)/$(TARGET2)

$(TARGET3): $(SRC)/advanced_array_function.c $(TESTDIR)/test_merge_intervals.c $(EXTRA)/Unity/unity.c $(BIN)
	$(CC) $(CFLAGS) $(SRC)/advanced_array_function.c \
	$(TESTDIR)/test_merge_intervals.c \
	$(EXTRA)/Unity/unity.c -o $(BIN)/$(TARGET3)

test1: $(TARGET1)
	./$(BIN)/$(TARGET1)

test2: $(TARGET2)
	./$(BIN)/$(TARGET2)

test3: $(TARGET3)
	./$(BIN)/$(TARGET3)

$(BIN):
	mkdir ./bin

clean:
	rm -rf $(BIN)

.PHONY: test clean