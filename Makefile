CC = g++
CFLAGS = -Iinc -Wall -g
SRC =  src/vector.cpp src/main.cpp 
OBJ = $(SRC:.cpp=.o)
TARGET = Program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)