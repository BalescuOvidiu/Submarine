DIRECTORY_BIN = bin
DIRECTORY_SRC = src
DIRECTORY_INC = include

LIBS = -lsfml-graphics -lsfml-window -lsfml-system
FLAGS = -Wall -std=gnu++0x

CC = g++

OBJECTS = gui.o button.o component.o panel.o main.o

TARGET = $(DIRECTORY_BIN)/Submarine

DEPS = $(patsubst %, $(DIRECTORY_BIN)/%, $(OBJECTS))

default: $(TARGET)

$(DIRECTORY_BIN)/%.o: $(DIRECTORY_SRC)/%.cpp
	$(CC) $(FLAGS) -I$(DIRECTORY_INC) -c $^ -o $@  

$(TARGET): $(DEPS)
	$(CC) $(DEPS) $(LIBS) $(FLAGS) -o $@

.PHONY: clean
clean:
	-rm -f $(DEPS) $(DIRECTORY_BIN)/$(TARGET)

run:
	./$(TARGET)