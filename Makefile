CC := gcc
CFLAGS := -Wall -g
LIBS := 
TARGET := run

SRC := $(shell find . -name '*.c')
HDR := $(shell find . -name '*.h')
OBJ := $(patsubst %.c, %.o, $(SRC))

.PHONY: clean tags
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS)

$(OBJ): %.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(TARGET)

tags:
	find . \( -name '*.c' -o -name '*.h' \) | etags -
