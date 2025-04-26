CC = g++
CFLAGS = -Iinc -Wall -g
SRC = src/vector.cpp src/deque.cpp src/list.cpp src/main.cpp # Ensure deque.cpp is included
OBJ = $(SRC:.cpp=.o)
TARGET = main.out # Match the target name used in launch.json

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET) tests/test_deque.out

# Testing target
tests: tests/test_deque.cpp src/deque.cpp
	$(CC) $(CFLAGS) tests/test_deque.cpp src/deque.cpp -o tests/test_deque.out

run-tests: tests
	./tests/test_deque.out