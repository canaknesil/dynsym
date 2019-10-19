CC := g++
CFLAGS := -Wall -g -std=c++14
LIBS := 
TARGET := run

SRC := $(shell find . -name '*.cpp')
HDR := $(shell find . -name '*.h')
OBJ := $(patsubst %.cpp, %.o, $(SRC))

.PHONY: clean tags
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS)

$(OBJ): %.o: %.cpp $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(TARGET)

tags:
	find . \( -name '*.cpp' -o -name '*.c' -o -name '*.h' \) | etags -
